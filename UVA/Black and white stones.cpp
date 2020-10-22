#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
string ch;
ll a,b;
ll dp[5005][5005];
ll rec(int pos,int i)
{
    if(pos>=ch.size() || i==0)
        return 0;
    if(dp[pos][i]!=-1)
        return dp[pos][i];
    ll res=0;
    if(ch[pos]=='B')
    {
        res += rec(pos+1,i-1);
    }
    else
    {
        ll res1=((a)+rec(pos+1,i-1));
        ll res2=(a-b)*i+rec(pos+1,i);
        res += min(res1,res2);
    }
    return dp[pos][i]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>a)
    {
        cin>>b>>ch;
        int b=0;
        for(int i=0;i<ch.size();i++)
        {
            if(ch[i]=='B')
            {
                b++;
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<rec(0,b)<<endl;
    }
    return 0;
}
