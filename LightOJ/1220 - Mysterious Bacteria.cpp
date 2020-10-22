#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        ll x;
        scanf("%lld",&x);
        bool d=0;
        if(x<0)
        {
            x=x*(-1);
            d=1;
        }
        ll sq=sqrt(x);
        ll mx=0;
        bool chk=0;
        for(ll j=2; j<=sq; j++)
        {
            ll ans=1;
            for(ll k=1;; k++)
            {
                ans = ans*j;
                if(ans==x)
                {
                    if(d==1)
                    {
                        if(k%2==0)
                        {
                            ll z=k;
                            while(z%2==0)
                            {
                                z=z/2;
                            }
                            mx=max(mx,z);
                        }
                        else mx=max(mx,k);

                        chk=1;
                    }
                    else
                    {
                        mx=max(mx,k);
                        chk=1;
                    }
                }
                if(ans>x)
                    break;
            }
        }
        if(chk==0)
        {
            printf("Case %d: %d\n",i,1);
        }
        else
        {
            printf("Case %d: %lld\n",i,mx);
        }


    }


    return 0;
}
