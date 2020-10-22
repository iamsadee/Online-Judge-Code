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
    long long int n ,i,j,x,y,count;
    while(scanf("%lld",&n)==1)
    {
        count=0;
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
                    count++;
                }
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
