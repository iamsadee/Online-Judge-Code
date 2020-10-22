#include<stdio.h>
#include<math.h>
int prime(long long n)
{
    long long int x ,i;
    x= sqrt(n);
    for(i=2;i<=x;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    long long int n ,i,j,x,y,c;
    while(scanf("%lld",&n)==1)
    {
        c=0;
        if(n==0)
            break;
        x=n/2;
        for(i=2;i<=x;i++)
        {
            if(prime(i))
            {
                y=n-i;
                if(prime(y))
                {
                    printf("%lld = %lld + %lld\n",n,i,y);
                    c=1;
                    break;
                }
            }
        }
        if(c==0)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
