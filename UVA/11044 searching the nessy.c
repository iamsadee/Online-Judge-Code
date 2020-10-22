#include<stdio.h>

int main()

{
    long long int t , n , m ,i , x , y , z;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&n,&m);
        x = n%3 ;
        y = m%3 ;
        z = ((n-x)*(m-y))/9 ;

        printf("%lld\n",z);

    }
    return 0;
}
