#include<stdio.h>

int main()


{
    int M , N ;
    long long int c ;
    while(scanf("%d %d",&M,&N)==2)
    {
        c = M*N - 1 ;
        printf("%lld\n",c);
    }
    return 0;
}
