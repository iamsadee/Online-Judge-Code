#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static bool vis[1000005];
vector<ll> prime;
void sieve()
{
    ll n=1000000;
    ll x=sqrt(n);
    int i,j;
    vis[1]=1;
    for(j=4;j<=n;j+=2)
    {
        vis[j]=1;
    }
    for(i=3;j<=x;i+=2)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=n;j+=2*i)
            {
                vis[j]=1;
            }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(vis[i]==0) prime.push_back(i);
    }
}
ll seg_seive(ll a,ll b)
{
    if(a==0) a++;
    ll x=sqrt(b);
    ll i,j;
    ll arr[100005];
    memset(arr,0,sizeof arr);
    for(i=0;i<prime.size() && prime[i]<=x ;i++)
    {
        ll p=prime[i];
        j=p*p;
        if(j<a)
        {
            j =  ((a+p-1)/p)*p;
        }
        for(;j<=b;j+=p)
        {
            arr[j-a]=1;
        }
    }
    ll res=0;
    for(i=a;i<=b;i++)
    {
        if(arr[i-a]==0)
            res++;
    }
    return res;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    sieve();
    int t;
    scanf("%d",&t);
    int i,j;
    for(i=1;i<=t;i++)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll ans=seg_seive(a,b);
        if(a==1)
            ans--;
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
