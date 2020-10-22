#include<stdio.h>

int main()


{
    long long int x , i , sum  , m ;
    while(scanf("%lld",&x)==1)
    {
        sum = 0 ;
        for(i=1;i<=x;i++)
        {
            m = i*i*i ;
            sum += m ;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
