#include<stdio.h>
int main()
{
    long long int a,b,t,i;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&a,&b);
        if(b%a==0)
            printf("%lld %lld\n",a,b);
        else printf("-1\n");
    }
    return 0;
}
