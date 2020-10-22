#include<stdio.h>
#include<math.h>
int main()

{
    double a , b , c , s , area , k ;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
    {
        s = (a+b+c)/2.0 ;

            k = s*(s-a)*(s-b)*(s-c) ;
            area = (4/3.0)*sqrt(k) ;
            //rintf("%0.3lf\n",area);
        if(area>0)
            printf("%0.3lf\n",area);
        else
        {
            area = -1 ;
            printf("%0.3lf\n",area);
        }


    }
    return 0;
}
