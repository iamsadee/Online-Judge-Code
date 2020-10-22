#include<stdio.h>
int main()


{
    int T , N , i , x ;

    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        x = 2*N -1 ;

        printf("Case #%d: %d\n",i,x);
    }
    return 0;
}
