#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 2*acos(0.0)
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int ks=1;ks<=t;ks++)
    {
        ll n,m;
        scanf("%lld %lld",&n,&m);
        ll a1,a2,d,tot;
        a1=(m*(m+1))/2;
        ll p=m+m;
        a2=(p*(p+1))/2 - a1;
        ll q=p+m;
        d=(q*(q+1))/2 - (p*(p+1))/2;
        d=d-a1;
        tot=(n/(2LL*m));
        ll ans=(tot*(2*a2+(tot-1)*d))/2  - (tot*(2*a1+(tot-1)*d))/2;
        printf("Case %d: %lld\n",ks,ans);

    }
    return 0;
}
