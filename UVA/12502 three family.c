#include<stdio.h>

int main()


{
    long long int T, i , x , y,z , u ,v ,a ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        u = ((x*60)+(y*60))/3 ;
        v = ((x*60)-u)+((y*60)-u) ;
        a = (((x*60)-u)*z)/v ;
        printf("%lld\n",a);
    }
    return 0;
}
