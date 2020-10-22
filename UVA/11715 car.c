#include<stdio.h>

int main()

{
    int i=0 ;
    double n , s , u , v , a , t ;
    while(scanf("%lf",&n)==1)
    { i++ ;
        if(n==0)
            break;
        if(n==1)
        {
            scanf("%lf %lf %lf",&u,&v,&t);
            a = (v-u)/t ;
            s = (u*t)+((1/2.0)*a*t*t) ;
            printf("Case %d: %0.3lf %0.3lf\n",i,s,a);

        }

        else if(n==2)
        {
            scanf("%lf %lf %lf",&u,&v,&a);
            t = (v-u)/a ;
            s = (u*t)+((1/2.0)*a*t*t) ;
            printf("Case %d: %0.3lf %0.3lf\n",i,s,t);

        }
        else if(n==3)
        {
            scanf("%lf %lf %lf",&u,&a,&s);
            v = sqrt((u*u)+2*a*s) ;
            t = (v-u)/a ;
            printf("Case %d: %0.3lf %0.3lf\n",i,v,t);

        }
        else if(n==4)
        {
            scanf("%lf %lf %lf",&v,&a,&s);
            u = sqrt((v*v)-2*a*s) ;
            t = (v-u)/a ;
            printf("Case %d: %0.3lf %0.3lf\n",i,u,t);

        }
    }
    return 0;

}
