#include<stdio.h>

int main()

{
    long long int i , j , k , n , l , temp , age[20000] ;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&age[i]);
        }

        for(j=1;j<=n;j++)
        {
            for(k=j+1;k<=n;k++)
            {
                if(age[j]>=age[k])
                {
                    temp = age[j] ;
                    age[j] = age[k] ;
                    age[k] = temp ;
                }
            }
        }

        for(l=1;l<=n;l++)
        {
            printf("%lld",age[l]);
            if(l==n)
                break;
            printf(" ");

        }
        printf("\n");
    }
    return 0;
}
