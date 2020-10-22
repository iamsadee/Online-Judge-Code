#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool arr[1000005];
vector<ll> prime;
void seive()
{
    ll n=1000004;
    ll x=sqrt(n);
    ll i,j;
    arr[0]=1;
    arr[1]=1;
    for(i=4; i<=n; i+=2)
    {
        arr[i]=1;
    }
    for(i=3; i<=x; i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i; j<=n; j+=2*i)
            {
                arr[j]=1;
            }
        }
    }
    for(i=2; i<=n; i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}
struct A
{
    ll x,y;
};
vector<A>factors;
ll m;
void factorize( ll n )
{
    ll sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ )
    {
        ll cnt=0;
        if ( n % prime[i] == 0 )
        {
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                cnt++;
            }
            A a;
            a.x=prime[i];
            a.y=(ll)cnt*m;
            a.y++;
            factors.push_back(a);
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        A a;
        a.x=n;
        a.y=1LL*m;
        a.y++;
        factors.push_back(a);
    }
}
ll bigmod(ll n,ll m)
{
    if(m==0)
        return 1;
    if(m%2!=0)
    {
        return (n*bigmod(n,m-1))%1000000007;
    }
    else
    {
        ll x=bigmod(n,m/2);
        return (x*x)% 1000000007;
    }
}

int main()
{
    int t,k;
    seive();
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        ll n;
        scanf("%lld %lld",&n,&m);
        factors.clear();
        factorize(n);
        ll ans=1;
        ll mod=1000000007;
        for(int i=0;i<factors.size();i++)
        {
            //cout<<factors[i].x<<" "<<factors[i].y<<endl;
            ans = (ans%mod * ((bigmod(factors[i].x,factors[i].y)%mod-1LL%mod)%mod)%mod)%mod;
            //cout<<ans<<endl;
            ans = (ans%mod * bigmod(factors[i].x-1LL,mod-2)%mod)%mod;
            //cout<<ans<<endl;
        }
        if(ans<0)
            ans += mod;
        printf("Case %d: %lld\n",k,ans);

        //printf("Case %d: %lld\n",k,res);
    }
    return 0;
}
