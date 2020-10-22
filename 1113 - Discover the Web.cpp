#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        stack<string> frwrd,bckwrd;
        string cur="http://www.lightoj.com/";
        string ch;
        printf("Case %d:\n",i);
        while(cin>>ch && ch!="QUIT")
        {
            string a;
            if(ch=="VISIT")
            {
                cin>>a;
                bckwrd.push(cur);
                while(frwrd.size()>0)
                {
                    frwrd.pop();
                }
                cur=a;
                cout<<cur<<'\n';
            }
            else if(ch=="BACK")
            {
                if(bckwrd.size()==0)
                {
                    cout<<"Ignored"<<'\n';
                }
                else
                {
                    frwrd.push(cur);
                    cur=bckwrd.top();
                    bckwrd.pop();
                    cout<<cur<<'\n';

                }
            }
            else if(ch=="FORWARD")
            {
                if(frwrd.size()==0)
                {
                    cout<<"Ignored"<<'\n';
                }
                else
                {
                    bckwrd.push(cur);
                    cur=frwrd.top();
                    frwrd.pop();
                    cout<<cur<<'\n';
                }
            }
        }
    }
    return 0;
}
