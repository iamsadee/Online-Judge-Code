#include<stdio.h>
#include<math.h>
int main()
{
    long long int T , i , a , b , c ;
    double x , y , z;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        x = sqrt(a*a+b*b);
        y = c-x;
        z = c+x;
        printf("%.2lf %0.2lf\n",y,z);
    }
    return 0;
}
