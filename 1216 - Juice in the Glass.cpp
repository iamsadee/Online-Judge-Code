#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI acos(-1)
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double r1,r2,h,p;
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
        double R=r2+(((p*(r1-r2)))/(h*1.0));
        double res=((PI*p)*(R*R+R*r2+r2*r2))*(1/3.0);
        printf("Case %d: %0.8lf\n",i,res);
    }
    return 0;
}
