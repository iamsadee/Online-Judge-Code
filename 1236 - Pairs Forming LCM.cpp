#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static bool arr[10000005];
vector<ll> prime;
void seive()
{
    int n=10000002;
    int x=sqrt(n);
    int i,j;
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
ll fact(ll x)
{
    ll sq=sqrt(x);
    ll ans=1;
    for(int i=0;i<prime.size() && prime[i]<=sq;i++ )
    {
        if(x%prime[i]==0)
        {
            ll cnt=0;
            while(x%prime[i]==0)
            {
                x=x/prime[i];
                cnt++;
            }
            ans = ans*(2LL*cnt+1LL);
        }
        sq=sqrt(x);
    }
    if(x!=1)
    {
        ans = ans*(2LL*1LL+1LL);
    }
    return ans;
}
int main()
{
    ll n;
    int t;
    seive();
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        ll res= fact(n);
        res= res/2;
        res++;
        printf("Case %d: %lld\n",i,res);
    }
    return 0;
}
