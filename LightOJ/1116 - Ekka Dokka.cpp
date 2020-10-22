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
        ll w;
        scanf("%lld",&w);
        if(w%2==1)
        {
            printf("Case %d: Impossible\n",ks);
        }
        else
        {
            ll x=w;
            while(x%2==0)
            {
                x=x/2;
            }
            ll y=w/x;
            printf("Case %d: %lld %lld\n",ks,x,y);
        }
    }
    return 0;
}
