#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[1000005];
ll mod=1000000007;
ll bigmod(ll a,ll p,ll m)
{
    if(p==0)
        return 1%m;
    if(p%2!=0)
    {
        return (a*(bigmod(a,p-1,m)))%m;
    }
    else
    {
        ll x=(bigmod(a,p/2,m))%m;
        return (x*x)%m;
    }
}
ll ncr(ll n,ll r)
{
    ll x=fact[n];
    ll y=fact[r]*fact[n-r];
    if(y>=mod) y=y%mod;
    y=bigmod(y,mod-2,mod);
    x=x*y;
    if(x>=mod)
        x=x%mod;
    return x;
}
ll mul(ll x,ll y)
{
    return (x*y)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0]=1LL;
    for(ll i=1;i<=1e6;i++)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod) fact[i]%=mod;
    }
    int t;
    cin>>t;
    for(int ks=1;ks<=t;ks++)
    {
        int n;
        cin>>n;
        ll arr[n+2];
        ll ans=1LL;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        for(int i=n-1;i>=1;i--)
        {
            ans=mul(ans,ncr(sum-1LL,arr[i]-1));
            sum -=arr[i];
        }
        cout<<"Case "<<ks<<": "<<ans<<"\n";
    }
    return 0;
}
