#include<stdio.h>
int main()


{
    long long int S , D , i , x ,c , j  ;
    while(scanf("%lld %lld",&S,&D)==2)
    {
         x=S ;
         for(i=S+1;x<D;i++)
         {
             x +=i ;
             S++;


         }
         printf("%lld\n",S);

    }
    return 0;


}
