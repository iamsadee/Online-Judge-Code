#include<stdio.h>
int main()
{
    long long int T , k , i , x ;
    double a, b , c , d , tax ;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        a=0 , b=0 , c=0 , d=0 , tax=0;
        scanf("%lld",&k);
        if(k>180000 )
        {
            tax = k - 180000 ;
            if(tax>=300000)
            {
                a = 30000 ;
            }
            else if(tax <300000)
            {
                a = ((10*tax)/100.0);
            }
        }
        if(k>480000 )
        {
            tax = k - 480000 ;
            if(tax>400000)
            {
                b = 60000 ;
            }
            else
            {
                b = ((15*tax)/100.0);
            }
        }
        if(k>880000 )
        {
            tax = k - 880000 ;
            if(tax>=300000)
            {
                c = 60000 ;
            }
            else
            {
                c = (20*tax)/100.0 ;
            }
        }
        if(k>1180000)
        {
            tax = k - 1180000 ;
            d = ((25*tax)/100.0) ;
        }
        tax = a + b + c + d;
        if(tax>0 && tax<=2000)
            printf("Case %lld: 2000\n",i);
        else
        {
            x = tax ;
            if(x<tax)
            printf("Case %lld: %lld\n",i,x+1);
            else
            printf("Case %lld: %lld\n",i,x);
        }
    }
    return 0;
}
