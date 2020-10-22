#include<stdio.h>

int main()

{
    int N , x,a , b , rem ,cola ;
    while(scanf("%d",&N)==1)
    {
        x=0 ;
        b=N;
        if(N==2)
        {
            N++;
        }
        while(N>=3)
        {
            a=N/3;
            x+=a ;
            rem = N%3 ;
            N = a + rem ;
            if(N==2)
            {
                x++;

            }
        }
        cola = b+x;
        printf("%d\n",cola);
    }
    return 0;
}
