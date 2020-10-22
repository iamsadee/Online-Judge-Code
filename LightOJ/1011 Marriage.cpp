#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll arr[17][17];
static int dp[17][1<<16];
//map<int,int> mp[1<<16];
ll fun(int i,int mask2)
{
    //cout<<sum<<endl;
    if(i>=n)
    {
        ll req=(1LL<<n)-1LL;
        if(req==mask2)
            return 0;
        else return -1;
    }
    if(dp[i][mask2]!=-1)
        return dp[i][mask2];
    ll ans=0,ans1=0;
    for(int k=0;k<n;k++)
    {
        ll chk=(mask2&(1LL<<k));
        if(chk==0)
        {
            //ans =;
            ans =arr[i][k]+fun(i+1,mask2|(1LL<<k));
            ans1=max(ans,ans1);
            //ans1 = fun(i+1,mask1,mask2,sum);
        }
    }
    return dp[i][mask2]=ans1;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        memset(dp,-1,sizeof dp);
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
               scanf("%lld",&arr[j][k]);
            }
        }
        ll ans=fun(0,0);
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
