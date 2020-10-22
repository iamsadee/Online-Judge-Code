#include<stdio.h>
#include<math.h>
int main()


{
    long long int n , p , i ;
    double count ;
    while(scanf("%lld %lld",&n,&p)==2)
    {
        count = 0 ;

        count = pow(p,1.0/n);
        printf("%lf\n",count);

    }


}


