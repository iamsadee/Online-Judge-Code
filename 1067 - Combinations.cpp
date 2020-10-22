#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//static double arr[1000005];
//arr[0]=0.0;
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
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    static ll arr[1000005];
    arr[0]=1;
    for(int i=1;i<=1000002;i++)
    {
        arr[i] =((arr[i-1]%1000003)*(i%1000003))%1000003;
    }
    int t;
    scanf("%d",&t);
    int i,j,k;
    for(i=1;i<=t;i++)
    {
        ll n,r,m=1000003;
        scanf("%lld %lld",&n,&r);
        ll ans = ((arr[n]%m)*(bigmod(arr[r],m-2,m)%m)*(bigmod(arr[n-r],m-2,m)%m))%m;
        cout<<"Case "<<i<<": "<<ans<<'\n';
    }
    return 0;
}
