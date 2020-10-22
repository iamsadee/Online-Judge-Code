
#include<stdio.h>
int main()

{
    long long int a , b , c , n  ;

    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
            a=0;
            b=1;




        while(n!=0)
        {
            c= a+b ;

            a = b ;
            b = c ;
            n--;

        }
        printf("%lld\n",b);

    }

    return 0;


}
