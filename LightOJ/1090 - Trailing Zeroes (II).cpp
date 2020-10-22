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
    int t;
    scanf("%d",&t);
    int i,j,k;
    for(i=1;i<=t;i++)
    {
        ll p,q,n,r;
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        ll five=0,two=0;
        ll z=n;
        while(z>=5)
        {
            five += z/5;
            z/=5;
        }
        z=n;
        while(z>=2)
        {
            two += z/2;
            z/=2;
        }
        ll five1=0,two1=0;
        z=r;
        while(z>=5)
        {
            five1+=z/5;
            z/=5;
        }
        z=r;
        while(z>=2)
        {
            two1 += z/2;
            z/=2;
        }
        z=n-r;
        while(z>=5)
        {
            five1+=z/5;
            z/=5;
        }
        z=n-r;
        while(z>=2)
        {
            two1 += z/2;
            z/=2;
        }
        ll five2=0,two2=0;
        z=p;
        while(z%5==0)
        {
            five2++;
            z/=5;
        }
        z=p;
        while(z%2==0)
        {
            two2++;
            z/=2;
        }
        //ll ans = min(five-five1,two-two1);
        //cout<<five<<' '<<five1<<endl;
        //cout<<two<<' '<<two1<<endl;
        five += q*five2;
        two += q*two2;
        ll ans = min(five-five1,two-two1);
        cout<<"Case "<<i<<": "<<ans<<'\n';

    }
    return 0;
}
