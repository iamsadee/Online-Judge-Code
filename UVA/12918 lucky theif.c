#include<stdio.h>
int main()
{
    long long int i , T , j , n , m , sum  ;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        sum = 0;
        scanf("%lld %lld",&n,&m);
        for(j=1;j<=n;j++)
        {
            m-- ;
            sum += m ;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
