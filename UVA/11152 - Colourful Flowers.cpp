#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI acos(-1)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        double s=(a+b+c)/2.0;
        double area=sqrt(s*(s-a)*(s-b)*(s-c));
        double in_r=area/(s*1.0);
        double in=PI*in_r*in_r;
        double blue=area-in;
        double out=(PI*((a*b*c)/sqrt((a+b+c)*(b+c-a)*(a+c-b)*(a+b-c))*1.0)*((a*b*c)/sqrt((a+b+c)*(b+c-a)*(a+c-b)*(a+b-c))*1.0));
        double yellow = out-area;
        cout<<setprecision(4);
        cout<<fixed;
        cout<<yellow<<' '<<blue<<' '<<in<<'\n';
    }
    return 0;
}
