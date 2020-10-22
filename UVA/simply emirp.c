#include<stdio.h>
#include<math.h>


int main()

{
    long long int N , i , j , k , count , rev ,c , rem ,a ;
    while(scanf("%lld",&N)==1)
    {
        count = 0 ;
        for(i=2;i<=sqrt(N);i++)
        {
            if(N%i ==0)
            {
                count++;
            }
        }
        if(count == 0)
        {
            rev =0 ;
            a = N ;

            while(a!=0)
            {
               rev = rev * 10;
                rev = rev + a%10;
                a = a/10;

            }
            k= 0 ;

            for(j=2;j<=sqrt(rev);j++)
            {
                if(rev%j == 0)
                {
                    k++ ;
                }

            }
            if(k==0 && rev != N)
            {
                printf("%lld is emirp.\n",N);
            }
            else printf("%lld is prime.\n",N);


        }
        else printf("%lld is not prime.\n",N);

    }
    return 0;
}
