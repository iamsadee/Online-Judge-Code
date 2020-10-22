#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[55];
int ase[55];
int n,k;
ll mod=100000007;
ll dp[51][1002];
ll fun(int pos,int sum)
{
    if(sum==0)
        return 1LL;
    if(sum<0)
        return 0;
    if(pos>=n)
    {
        if(sum==0)
        {
            return 1LL;
        }
        else
        {
            return 0;
        }
    }
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    ll res=0;
    for(int i=0; i<=ase[pos]; i++)
    {
        if((sum-arr[pos]*i)>=0)
        {
            res += fun(pos+1,sum-(arr[pos]*i));
            if(res>=mod)
{
    res=res%mod;
}
        }
    }
    return dp[pos][sum]=res;
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
        cin>>n>>k;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>ase[i];
        }
        memset(dp,-1,sizeof dp);
        ll res=fun(0,k);
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
