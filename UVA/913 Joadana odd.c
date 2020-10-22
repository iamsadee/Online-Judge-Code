#include<stdio.h>
int main()
{
    long long int n,x,y,z ,i;
    while(scanf("%lld",&n)==1)
    {
        n = (n+1)/2;
        x= n*n ;
        y= 2*x -1;
        z=y;
        for(i=1;i<=2;i++)
        {
            y=y-2;
            z += y;
        }
        printf("%lld\n",z);
    }
    return 0;
}

