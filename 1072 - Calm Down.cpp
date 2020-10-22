#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535898
double binary(double R,int n)
{
    double low , mid , high , ans,p,t;
    low=0;
    high=R;
    while(abs(low-high)>=0.000000001)
    {
        mid=(low+high)/2.0;
        t = acos((((R-mid)*(R-mid))+((R-mid)*(R-mid))-(4*mid*mid))/(2*(R-mid)*(R-mid)*1.0));
        t = (t*180)/(PI*1.0);
        p=(360/(t*1.0));
        if(p>=n)
        {
            low=mid;
            ans=mid;
        }
        else
        {
            high = mid;
            //ans=mid;
        }
    }
    return ans;
}

int main()
{
    double ans , R ;
    int n,t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %d",&R,&n);
        ans=binary(R,n);
        printf("Case %d: %0.10lf\n",i,ans);
    }
    return 0;
}
