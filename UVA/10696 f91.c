#include<stdio.h>
int main()

{
    long long N ;
    while(scanf("%lld",&N)==1)
    {
        if(N==0)
            break;
        else if(N<=100)
        {
            printf("f91(%lld) = 91\n",N);
        }
        else if(N>=101)
        {
            printf("f91(%lld) = %lld\n",N,N-10);
        }

    }
    return 0;
}
