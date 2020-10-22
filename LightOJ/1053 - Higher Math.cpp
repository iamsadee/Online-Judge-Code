#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int i,j,n;
    int t,q;
    scanf("%d",&t);
    int a[1005];
    for(int m=1;m<=t;m++)
    {
        ll x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        bool chk=0;
        if(x*x + y*y == z*z)
        {
            chk=1;
        }
        else if(x*x == y*y + z*z)
        {
            chk=1;
        }
        else if(y*y==z*z+x*x)
        {
            chk=1;
        }
        if(chk==1)
        {
            printf("Case %d: yes\n",m);
        }
        else printf("Case %d: no\n",m);

    }

    return 0;
}
