#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll s;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld",&s);
        ll x1=sqrt(s);
        ll y1=ceil(sqrt(s));
        ll z1=(y1*y1)-(x1*x1);
        ll X,Y;
        if(s==2)
        {
            X=1;
            Y=2;
        }
        else if(s==3)
        {
            X=2;
            Y=2;
        }
        else if((y1*y1)==s)
        {
            if((y1*y1)%2==0)
            {
                X=y1;
                Y=1;
            }
            else
            {
                X=1;
                Y=y1;
            }
        }
        else if((y1*y1) %2==0)
        {
            if((1+(x1*x1)+z1/2)>s)
            {
                X=s%(x1*x1);
                Y=y1;
            }
            else if((1+(x1*x1)+z1/2)==s)
            {
                X=y1;
                Y=y1;
            }
            else
            {
                X=y1;
                Y=((y1*y1)%s)+1;
            }
        }
        else
        {
            if((1+(x1*x1)+z1/2)>=s)
            {
                Y=s%(x1*x1);
                X=y1;
            }
            else if((1+(x1*x1)+z1/2)==s)
            {
                X=y1;
                Y=y1;
            }
            else
            {
                Y=y1;
                X=((y1*y1)%s)+1;
            }
        }
        printf("Case %d: %lld %lld\n",i,X,Y);
    }

    return 0;
}
