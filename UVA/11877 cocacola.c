#include<stdio.h>
int main()

{
    int n , a,b, c , d , i ;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        a=0;
        while(n>=3)
        {
            c = n/3 ;
            d = n%3 ;
            a =a+ c ;
            n= d+c ;
             if(n==2)
            {
                n++;
            }


        }
        printf("%d\n",a);
    }
    return 0;
}
