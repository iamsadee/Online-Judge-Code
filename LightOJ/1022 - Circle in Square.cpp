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
       double r;
       scanf("%lf",&r);
       double sq=r*2;
       double ans=(sq*sq)-(PI*r*r);
       printf("Case %d: %0.2lf\n",ks,ans);
    }
    return 0;
}
