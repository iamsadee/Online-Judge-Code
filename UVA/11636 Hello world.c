#include<stdio.h>

int main()


{
    int i ,j=1, N , a , b ;

    while(scanf("%d",&N)==1)
    {
        if(N<0)
            break;
        a = 2;
        b=1;
        for(i=1;b<N;i++)
        {
            b=a*b ;
        }
        printf("Case %d: %d\n",j,i-1);
        j++;

    }
    return 0;
}
