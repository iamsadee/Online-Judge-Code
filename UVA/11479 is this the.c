#include<stdio.h>

int main()

{
    long long int T , a , b , c , i ;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a+b>c && b+c>a && c+a>b )
        {
            if(a==b && b==c && c==a)
            {
                printf("Case %lld: Equilateral\n",i);
            }
            else if((a==b && b!=c) || (b==c && c!=a) ||(c==a && a!=b))
                printf("Case %lld: Isosceles\n",i);
            else if(a!=b && b!=c && c!=b )
            {
                printf("Case %lld: Scalene\n",i);
            }

        }

        else printf("Case %d: Invalid\n",i);
    }
    return 0;
}
