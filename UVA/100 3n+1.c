#include<stdio.h>
int main()
{
    long long int a , b , i , j , n,mx ,k,l;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        mx=0;
        if(a>=b)
        {
            k=b;
            l=a;
        }
        else
        {
            k=a;
            l=b;
        }
        for(i=k;i<=l;i++)
        {
            n=i;
            j=1;
            while(n!=1)
            {
                if(n%2==1)
                {
                    n=n*3+1;
                    j++;
                }
                else
                {
                    n=n/2;
                    j++;
                }
            }
            if(mx<=j)
            {
                mx=j;
            }
        }
        printf("%lld %lld %lld\n",a,b,mx);
    }
    return 0;
}
