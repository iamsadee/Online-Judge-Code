#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[105];
int n;
ll dp[105][105];
ll fun(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r]!=-1)
        return dp[l][r];
    ll res=-1e8;
    ll a=0;
    for(int i=l;i<=r;i++)
    {
        a += arr[i];
        res=max(res,a-fun(i+1,r));
    }
    a=0;
    for(int i=r;i>=l;i--)
    {
        a+=arr[i];
        res=max(res,a-fun(l,i-1));
    }
    return dp[l][r]=res;
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
        memset(dp,-1,sizeof dp);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll res=fun(0,n-1);
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
