#include<stdio.h>

int main()

{
    long long int N , i , k , rem=0 , num[1000] ;

    while(scanf("%lld",&N)==1)
    {
        if(N<0)
            break;
        i = 1 ;
        for(;;)
        {
            rem = N%3 ;
            num [i] = rem ;
            N = N/3 ;
            i++ ;
            if(N==0)
                break;
        }

        for(k=i-1;k>=1;k--)
        {
            printf("%lld",num[k]);
        }
        printf("\n");
    }
    return 0;
}
