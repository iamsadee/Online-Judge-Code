#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll csod(ll n)
{
    ll sum=0;
    ll x=sqrt(n);
    for(ll i=2;i<=x;i++)
    {
        ll j=n/i;
        sum += (j*(j+1LL))/2LL;
        sum -= (i*(i-1LL))/2LL;
        sum += i*(j-i);
    }
    return sum;
}
int main()
{

    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        ll n;
        scanf("%lld",&n);
        ll ans=csod(n);
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
