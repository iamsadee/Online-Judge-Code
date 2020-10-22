#include<stdio.h>
#include<math.h>

int main()

{
    long long int i , a , b , c , count , x ;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        if(a==0 && b==0)
            break ;
        count = 0 ;
        for(i=a;i<=b;i++)
        {
            if(a<=b)
            {
                c = sqrt(a) ;
                x = c*c ;
                if(x == a)
                {
                    count++ ;
                }
            }

            a++ ;
        }
        printf("%lld\n",count);
    }
    return 0;

}
