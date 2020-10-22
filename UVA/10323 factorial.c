#include<stdio.h>
int main()

{
    long long int n , i , fac ;
    while(scanf("%lld",&n)==1)
    {
        fac = 1;
        if(n<0)
        {
            n = n*(-1) ;
            if(n%2==1)
                printf("Overflow!\n");
            else printf("Underflow!\n");
        }
        else
        {
            for(i=1;i<=n;i++)
            {
                fac *= i ;
                if(i==14)
                    break;
            }
            if(fac>6227020800)
            {
                printf("Overflow!\n");
            }
            else if(fac<10000)
                printf("Underflow!\n");
            else printf("%lld\n",fac);
        }

    }

    return 0;

}

