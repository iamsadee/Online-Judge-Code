#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
double binary(int p,int q,int r ,int s , int t , int u)
{
    double low, high,mid , ans,eq;
    low=0;
    high =1;
    while(abs(low-high)>=0.0000001)
    {
        mid= (low+high)/2.0;
        eq = p*exp(-1*mid) +q * sin(mid) +r * cos(mid) +s * tan(mid)+t*(mid*mid) +u;
        if(eq>=0)
        {
            low=mid;
            ans=mid;
        }
        else
        {
            high = mid;
        }
    }
    return ans;
}
int main()
{
    int p,q,r,s,t,u;
    double ans,eq,eq1;
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6)
    {
        double mid;
        ans = binary(p,q,r,s,t,u);
        mid=1;
        eq = p*exp(-1*mid) +q * sin(mid) +r * cos(mid) +s * tan(mid)+t*(mid*mid) +u;
        mid=0;
        eq1 = p*exp(-1*mid) +q * sin(mid) +r * cos(mid) +s * tan(mid)+t*(mid*mid) +u;
        if((eq*eq1)>0 )
        {
            printf("No solution\n");
        }
        else
        {
            printf("%0.4lf\n",ans);
        }
    }
    return 0;
}
