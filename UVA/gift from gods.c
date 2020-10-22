#include<stdio.h>
#include<math.h>

long long int rev(long long int n)
{
    long long int rev =0 , x ;
    while(n!=0)
    {
        rev = rev*10;
        rev = rev + n%10 ;
        n=n/10;
    }
    return rev;
}

long long int prime(long long int n)
{
    long long int i , count=0 , c ;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0 )
        {
            count =1 ;

        }

    }
    if(count == 0)
    {
        c = n;
        return c;
    }
    else
    {
        return 0;
    }
}

int main()

{
    long long int n,x,b ;
    while(scanf("%lld",&n)==1)
    {
        x = rev(n);
        b = prime(n);
        printf("%lld\n",2*n);
        if(n==x && b == n)
        {
            break;
        }

    }
    return 0;
}
