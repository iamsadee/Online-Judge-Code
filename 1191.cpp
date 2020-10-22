#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m;
ll dp[52][52][52];
string a;
ll fun(int pos,int cnt,int bar)
{
    if(pos==0 && bar==0) return 1LL;
    if(pos<0 || bar<0) return 0;
    if(dp[pos][cnt][bar]!=-1)
        return dp[pos][cnt][bar];
    ll res=0;
    for(int i=1;i<=cnt;i++)
    {
        res += fun(pos-i,cnt,bar-1);
    }
    return dp[pos][cnt][bar]=res;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
   //cout.tie(NULL);
    memset(dp,-1,sizeof dp);
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d %d %d",&n,&k,&m);
        ll res=fun(n,m,k);
        printf("Case %d: %lld\n",ks,res);
    }
    return 0;
}
