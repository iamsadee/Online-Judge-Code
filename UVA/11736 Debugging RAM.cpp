#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
        int i,j;
        getchar();
        string ch;
        map<string,bool> st;
        vector< pair<string,int> > arr;
        int x;
        for(i=1;i<=m;i++)
        {
            cin>>ch>>x;
            st[ch]=1;
            arr.push_back(make_pair(ch,x));
            //cout<<ch<<' '<<x<<endl<<endl;
        }
        getchar();
        map<string,ll> mp;
        for(j=0;j<arr.size();j++)
        {
            string a;
            for(i=0;i<arr[j].second;i++)
            {
                getline(cin,ch);
                a +=ch;
            }
            int bit=a.size()-1;
            ll y=0;
            ll kor;
            for(i=0;i<a.size();i++)
            {
                //y = y+ (a[i]-'0')*pow(2.0,bit*1.0);
                kor=1;
                for(int k=0;k<bit;k++)
                {
                    kor *=2;
                }
                if(a[i]=='1')
                {
                    y += kor;
                }
                bit--;
            }
            //cout<<y<<endl;
            mp[arr[j].first]=y;
        }
        int t;
        scanf("%d",&t);
        getchar();
        for(i=0;i<t;i++)
        {
            cin>>ch;
            if(st[ch]==0)
            {
                cout<<ch<<"="<<endl;
            }
            else
            {
                cout<<ch<<"="<<mp[ch]<<endl;
            }
        }
    }
    return 0;
}
