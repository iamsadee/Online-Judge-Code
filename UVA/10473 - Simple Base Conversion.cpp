#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string ch;
    while(cin>>ch)
    {
        if(ch[0]=='-')
            break;
        int n=ch.size();
        ll res=0;
        string ans;
        if(n>=2 && ch[0]=='0' && ch[1]=='x')
        {
            int x=n-3;
            for(int i=2;i<n;i++)
            {
                int z;
                ll ans=1;
                for(int j=0;j<x;j++)
                {
                    ans *=16;
                }
                if(ch[i]>='0' && ch[i]<='9')
                {
                    z=ch[i]-'0';
                }
                else if(ch[i]=='A')
                {
                    z=10;
                }
                else if(ch[i]=='B')
                {
                    z=11;
                }
                else if(ch[i]=='C')
                {
                    z=12;
                }
                else if(ch[i]=='D')
                {
                    z=13;
                }
                else if(ch[i]=='E')
                {
                    z=14;
                }
                else if(ch[i]=='F')
                {
                    z=15;
                }
                res += (z*ans);
                x--;
                //cout<<res<<endl;
            }
            cout<<res<<'\n';
        }
        else
        {
            ll y=0;
            for(int i=0;i<n;i++)
            {
                y = y*10;
                y += (ch[i]-'0');
            }
            while(y!=0)
            {
                ll x=y%16;
                if(x<=9)
                {
                    ans.push_back(x+'0');
                }
                else if(x==10)
                {
                    ans.push_back('A');
                }
                else if(x==11)
                {
                    ans.push_back('B');
                }
                else if(x==12)
                {
                    ans.push_back('C');
                }
                else if(x==13)
                {
                    ans.push_back('D');
                }
                else if(x==14)
                {
                    ans.push_back('E');
                }
                else if(x==15)
                {
                    ans.push_back('F');
                }
                y=y/16;
            }
            ans.push_back('x');
            ans.push_back('0');
            reverse(ans.begin(),ans.end());
            cout<<ans<<'\n';
        }
    }
    return 0;
}
