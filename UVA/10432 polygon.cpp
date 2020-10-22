#include<bits/stdc++.h>
using namespace std;
#define pi (acos(-1))
int main()
{
    double r,ans;
    int n;
    while(scanf("%lf %d",&r,&n)==2)
    {
        //cout<<pi<<endl;
        double si=sin((2*pi)/(n*1.0));
        ans = 0.5*(n*r*r)*si;
        printf("%0.3lf\n",ans);
    }
    return 0;
}
