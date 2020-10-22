#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ch[55];
bool cmp(string a,string b)
{
    if((b+a)>=(a+b))
        return true;
    else return false;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        getchar();
        //ch.clear();
        //string yo;
        if(n==0)
            break;
        int i,j;
        for(i=0;i<n;i++)
        {
            cin>>ch[i];
            //ch.push_back(yo);
        }
        sort(ch,ch+n,cmp);
        for(i=n-1;i>=0;i--)
        {
            cout<<ch[i];
        }
        cout<<endl;

    }
    return 0;
}
