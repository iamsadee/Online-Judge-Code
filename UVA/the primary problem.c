
#include<stdio.h>
#include<math.h>
int prime(long long int n)
{
    long long int i,x;
    x=sqrt(n);
    for(i=2;i<=x;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    long long int i ,j,n,x,y,z,c;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        x=sqrt(n)+1;
        for(i=2;i<=x;i++)
        {
            c=0;
            if(prime(i))
            {
                z=n-i;
                if(prime(z))
                {
                    c=1;
                    printf("%lld:\n%lld+%lld\n",n,i,z);
                    break;
                }
            }
        }
        if(c==0)
            printf("%lld:\nNO WAY!\n",n);
    }
    return 0;
}
