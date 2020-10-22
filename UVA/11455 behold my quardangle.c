#include<stdio.h>

int main()


{
    long long int a , b , c , d ,n,i , sort[4] ;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);


        if((a==c && a!=b) && (b==d && b!=a) ||((a==b && a!=c) && (c==d && c!=a)) || ((a==d && a!=b ) &&(b==c && b!=a ) ))
            {
                printf("rectangle\n");
            }
        else if((a==b) && (b==c) && (c==d) && (d==a))
            {
                printf("square\n");
            }
        else if(a+b+c > d && d+c+a > b && b+c+d > a && a+b+d >c)
            printf("quadrangle\n");
        else printf("banana\n");
    }
    return 0;
}
