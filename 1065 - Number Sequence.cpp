#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
ll x,y;
ll mod=1LL;
void multiply(ll a[2][2],ll b[2][2])
{
    ll mul[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            mul[i][j]=0;
            for(int k=0;k<2;k++)
            {
                mul[i][j] += (a[i][k]*b[k][j])%mod;
                if(mul[i][j]>=mod) mul[i][j]%=mod;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            a[i][j]=mul[i][j];
        }
    }
}
ll power(ll F[2][2],ll n)
{
    ll M[2][2]={{1,1},{1,0}};
    if(n==1)
    {
        return (F[0][0]+F[0][1])%mod;
    }
    power(F,n/2LL);
    multiply(F,F);
    if(n%2)
    {
        multiply(F,M);
    }
    return ((F[0][0]*y)%mod+(F[0][1]*x)%mod)%mod;
}
ll fibb(ll n)
{
    ll F[2][2] = {{1,1},{1,0}};
    if(n==0) return x;
    if(n==1)
    {
        return y;
    }
    return power(F,n-1);
}
int main()
{
    int t;
    scanf("%d",&t);
    int ks=1;
    while(t--)
    {
        ll n,m;
        scanf("%lld %lld %lld %lld",&x,&y,&n,&m);
        mod=1LL;
        for(int i=1;i<=m;i++)
        {
            mod=mod*10LL;
        }
        printf("Case %d: %lld\n",ks++,fibb(n));
    }
    return 0;
}
