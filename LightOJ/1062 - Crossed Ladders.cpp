#include<bits/stdc++.h>
using namespace std;
double binary(double x,double y,double z)
{
    double low , high , mid,ans,ad,bc,ef;
    low =0;
    high=y;
    while(abs(low-high)>=0.0000000001)
    {
        mid=(low+high)/2.0;
        ad=sqrt((y*y)-(mid*mid));
        bc=sqrt((x*x)-(mid*mid));
        ef=(ad*bc)/((bc+ad)*1.0);
        if(ef<=z)
        {
            high=mid;
            ans=mid;
        }
        else
        {
            low= mid;
        }
    }
    return ans;
}
int main()
{
    int t , i;
    double x,y,z,ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %lf %lf",&x,&y,&z);
        ans = binary(x,y,z);
        printf("Case %d: %0.10lf\n",i,ans);
    }
    return 0;
}

