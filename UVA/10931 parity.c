#include<stdio.h>

int main()

{
    long long int I , n =1 , rem , c , k  ;
    int bin[1000] ;
    while(scanf("%lld",&I)==1)
    {
        int count = 0;
        c=1 ;
        if(I==0)
            break;
        while(I!=0)
        {

             rem = I%2 ;
             {
                 if(rem==1)
                    {
                        count++;
                        bin[c] = rem ;
                    }
                else if(rem == 0)
                    {bin[c]=rem ;}
             }
             c++;
             I = I/2 ;

        }
        printf("The parity of ");
        for(k=c-1;k>=1;k--)
        {
            printf("%d",bin[k]);
        }
        printf(" is %d (mod 2).\n",count);
    }
    return 0;
}
