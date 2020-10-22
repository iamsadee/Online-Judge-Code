#include<stdio.h>

int main()

{
    int T , C , d , i ;
    double I , new , N ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&C,&d);

        I = ((C*9.0)/5.0) + 32 ;
        N = I + d ;
        new = ((N-32)*5.0)/9.0 ;

        printf("Case %d: %0.2lf\n",i,new);
    }
    return 0;
}
