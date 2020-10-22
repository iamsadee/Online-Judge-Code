#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static int prime[1562505];
static int ar[5761455+10];
static unsigned int dp[5761455+10];
bool ifnotPrime( int x)
{
    return (prime[x/64] & (1 << ((x >> 1) & 31)));
}
bool makeComposite(int x)
{
    prime[x/64] |= (1 << ((x >> 1) & 31));
}
int sz;
int cnt=0;
ll mod=4294967296;
void bitWiseSieve(int n)
{
    for (int i = 3; i * i <= n; i += 2)
    {
        if (!ifnotPrime( i))
            for (int j = i * i, k = i << 1; j < n; j += k)
                makeComposite(j);
    }
    dp[cnt]=2;
    ar[cnt]=2;
    cnt++;
    for (int i = 3; i <= n; i += 2)
        if (!ifnotPrime( i))
        {
            ar[cnt]=i;
            dp[cnt] = (dp[cnt-1]%mod * i)%mod;
            cnt++;
        }
}

long long LCM(int n)
{
    long long lcm = 1;
    int pos=upper_bound(ar,ar+cnt,n)-ar;
    pos--;
    ll ans=dp[pos];
    for(int i=0;i<cnt;i++)
    {
        ll x=ar[i]*ar[i];
        if(x>n)
            break;
        while(x<=n)
        {
            x=x*ar[i];
            ans = (ans%mod * ar[i]%mod)%mod;
        }
    }
    return ans;
}
int main()
{
    int t,k;
    //cout<<mod<<endl;
    bitWiseSieve(1e8);
    //cout<<prime.size()<<endl;
    scanf("%d",&t);
    //printf("%d",mod);
    for(k=1; k<=t; k++)
    {
        int n;
        scanf("%d",&n);
        ll res=LCM(n);
        printf("Case %d: %lld\n",k,res);

        //printf("Case %d: %lld\n",k,res);
    }
    return 0;
}
