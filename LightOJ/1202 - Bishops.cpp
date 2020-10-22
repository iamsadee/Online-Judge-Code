#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 2*acos(0.0)
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll r1,c1,r2,c2;
        scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);
        if(r1==r2 && c1==c2)
        {
            printf("Case %d: 0\n",a);
        }
        else if(abs(r1-r2)==abs(c1-c2))
        {
            printf("Case %d: 1\n",a);
        }
        else
        {
            if(abs(r1-r2)%2 == abs(c1-c2)%2)printf("Case %d: 2\n",a);
            else printf("Case %d: impossible\n",a);
        }
    }
    return 0;
}
