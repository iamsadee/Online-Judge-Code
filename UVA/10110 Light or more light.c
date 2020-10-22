#include<stdio.h>
#include<math.h>
int main()
{
    long long n , x,y;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        x=sqrt(n);
        if(x*x==n)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

