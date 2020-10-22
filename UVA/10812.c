#include<stdio.h>
int main()

{
    long long int n , s , d , i , a , b ;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&s,&d);
        if(s<d)
            printf("impossible\n");
        else if((s%2 ==0 && d%2 ==1)||((s%2==1 && d%2==0)))
            printf("impossible\n");

        else
        {
            a = (s+d)/2 ;
            b = s - a;
            printf("%lld %lld\n",a,b);
        }


    }
    return 0;
}
