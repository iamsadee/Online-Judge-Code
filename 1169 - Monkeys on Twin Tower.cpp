#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[1005],r[1005];
int tl[1005],tr[1005];
ll dp[1005][3];
int n;
ll fun(int pos,int mark)
{
    if(pos>=n)
        return 0;
    if(dp[pos][mark]!=-1)
        return dp[pos][mark];
    ll res=1e18;
    if(pos==0)
    {
        res=min(res,l[pos]+fun(pos+1,0));
        res=min(res,l[pos]+tl[pos+1]+fun(pos+1,1));
        res=min(res,r[pos]+fun(pos+1,1));
        res=min(res,r[pos]+tr[pos+1]+fun(pos+1,0));
    }
    else
    {
        if(mark==0)
        {
            res=min(res,l[pos]+fun(pos+1,mark));
            res=min(res,l[pos]+tl[pos+1]+fun(pos+1,1));
        }
        else
        {
            res=min(res,r[pos]+fun(pos+1,mark));
            res=min(res,r[pos]+tr[pos+1]+fun(pos+1,0));
        }
    }
    return dp[pos][mark]=res;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>l[i];
       }
       for(int i=0;i<n;i++)
       {
           cin>>r[i];
       }
       tl[0]=0;
       tr[0]=0;
       tl[n]=0;
       tr[n]=0;
       for(int i=1;i<n;i++)
       {
           cin>>tl[i];
       }
       for(int i=1;i<n;i++)
       {
           cin>>tr[i];
       }
       memset(dp,-1,sizeof dp);
       ll res=fun(0,0);
       cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
