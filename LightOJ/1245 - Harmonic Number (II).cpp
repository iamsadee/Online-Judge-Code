#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int t;
    scanf("%d",&t);
    for(int j=1; j<=t; j++)
    {
        ll x;
        scanf("%lld",&x);
        ll sum=0;
        ll sq=sqrt(x);
        for(ll i=1; i<=sq; i++)
        {
            ll y=x/i;
            sum +=y;
            ll a=x/(i+1);
            if(y != (x/y))
            {
                ll z= (y-(a))*(x/y);
                sum +=z;
            }

        }
        printf("Case %d: %lld\n",j,sum);

    }
    return 0;
}
