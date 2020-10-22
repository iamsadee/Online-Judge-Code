#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[100005];
int n,k;
vector<int> arr;
int pre[100005];
int fun(int pos)
{
    if(pos>=n)
    {
        return 0;
    }
    if(dp[pos]!=-1)
        return dp[pos];
    int res=1e6;
    int ne=(pre[pos]-pos)+1;
    if(ne>=3)
    {
        for(int j=pre[pos]; j>=pre[pos]-2; j--)
        {
            res=min(res,1+fun(j+1));
        }
    }
    return dp[pos]=res;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        arr.clear();
        scanf("%d %d",&n,&k);
        for(int i=1; i<=n; i++)
        {
            ll x;
            scanf("%lld",&x);
            arr.push_back(x);
        }
        k=k*2;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++)
        {
            pre[i]=upper_bound(arr.begin(),arr.end(),(arr[i]+k))-arr.begin();
            pre[i]--;
            //cout<<pre[i]<<" ";
        }
        memset(dp,-1,sizeof dp);
        int req=fun(0);
        if(req>=1e5) printf("Case %d: -1\n",ks);
        else printf("Case %d: %d\n",ks,req);
    }
    return 0;
}
