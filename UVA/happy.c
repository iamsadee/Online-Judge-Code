#include<stdio.h>

int main()

{
    long long int x , i , arr[1000] , a , sum  , N, p , j ;
    scanf("%lld",&p);
    for(j=1;j<=p;j++)
    {


    scanf("%lld",&N);

    x = N ;

    happy:
    i=0;
    sum = 0;
    while(N!=0)
    {
        a = N%10 ;
        arr[i] = a;
        sum += (a*a ) ;
        N = N/10 ;
        i++;

    }

    if(sum != 1 && sum < 10 )
    {
        printf("Case #%lld: %lld is an Unhappy number.\n",j,x);

    }
    else if(sum == 1 )
    {
        printf("Case #%lld: %lld is a Happy number.\n",j,x);
    }
    else
    {
        N = sum ;
        goto happy;
    }

    }
    return 0;

}


