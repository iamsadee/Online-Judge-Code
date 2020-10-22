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
    for(int a=1;a<=t;a++)
    {
        double v1,v2,v3,a1,a2;
        cin>>v1>>v2>>v3>>a1>>a2;
        double d1=((v1*v1)/(2.0*a1));
        double d2= ((v2*v2)/(2.0*a2))  ;
        double d=d1+d2;
        double t=max(sqrt(d1/(0.5*a1)),sqrt(d2/(0.5*a2)));
        double ans=t*v3;
        printf("Case %d: %0.8lf %0.8lf\n",a,d,ans);
    }
    return 0;
}
