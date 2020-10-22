#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 1000001
ll d[10005];
bool vis[10005];
//typedef long long ll;
void sieve()
{
    ll n=10005;
    ll x=sqrt(n);
    int i,j;
    vis[1]=1;
    for(j=4;j<=n;j+=2)
    {
        vis[j]=1;
    }
    for(i=3;i<=x;i+=2)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=n;j+=2*i)
            {
                vis[j]=1;
            }
        }
    }
}
int mob[10005];
void mobius_fun(int n)
{
    int i,j;
    sieve();
    for(int i=1;i<=n;i++)
    {
        mob[i]=1;
    }
    for(i=2;i<=n;i++)
    {
        if(vis[i]==0)
        {
            mob[i]=-1;
            for(j=i+i;j<=n;j+=i)
            {
                if((j%(i*i))==0)
                    mob[j]=0;
                else mob[j]=mob[j]*(-1);
            }
        }
    }
    //cout<<"mobius"<<endl;
}
ll arr[10005];
void divi(ll x)
{
    for(int i=1;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            d[i]+=1;
            if(x%(x/i)==0 && (x/i)!=i)
            {
                d[x/i]+=1;
            }
        }
    }
    //cout<<"divi"<<endl;
}
ll CPascal(int n , int k) {
    ll v = 1;
    for (int i = 1; i <= k; i++)
        v = v * (n + 1 - i) / i;
    return v;
}
ll extreme_gcd(ll n)
{
    ll res = CPascal(n,4);
    for(int i=2;i<=10000;i++)
    {
        //cout<<"Sadee"<<endl;
        res += mob[i]*CPascal(d[i],4);
    }
    return res;
}
int main()
{
    mobius_fun(10003);
    ll n;
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        memset(d,0,sizeof d);
        scanf("%lld",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
            divi(arr[j]);
        }
        ll res=extreme_gcd(n);
        printf("Case %d: %lld\n",k,res);
    }
    return 0;

}
