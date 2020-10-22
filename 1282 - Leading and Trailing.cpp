#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bigmod(ll a,ll p,ll m)
{
    m=(ll)1000;
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

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);
        ll last=bigmod(n,k,1000);
        double la = k*(log10(n))-floor(k*log10(n));
        double ans=pow(10.0,la);
        double f=ans*100.0;
        ll first=floor(f);

        printf("Case %d: %lld ",i,first);
        if(last<10)
        {
            printf("00%lld\n",last);
        }
        else if(last<100)
        {
            printf("0%lld\n",last);
        }
        else printf("%lld\n",last);
    }


    return 0;
}
