#include<stdio.h>

int main()

{
    long long int n,i , c ,rem, num[1000],x;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        i=1 ;
        x=0 ;
       loop:
            do
       {
            rem = n%10;
            num[i] = rem ;
            n=n/10;
            x+= num[i] ;
            i++ ;
        }
        while(n!=0);


        if(x>=10)
        {
            n = x ;
            x=0;
            goto loop;
        }

        printf("%lld\n",x);




    }
    return 0;

}

