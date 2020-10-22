#include<stdio.h>

int main()

{
    long long int a, cut ;
    {
        while(scanf("%lld",&a)==1)

        {
            if(a<0)
                break;
            if(a%2==1)
            {
                cut = (a*a+a+2)/2;
                printf("%lld\n",cut);
            }
            else if(a%2==0)
            {cut = ((a*a)/2+a/2+1) ;
            printf("%lld\n",cut);
            }
        }
    }
    return 0;
}
