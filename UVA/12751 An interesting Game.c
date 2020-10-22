#include<stdio.h>

int main()

{
    int T , N , K , X , i , j , m , n , sum , dif ;

    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&N,&K,&X);
        sum = 0;
        for(j=1;j<=N;j++)
        {
            sum +=j ;
        }
        dif =0 ;
        for(m=X;m<=(X+K-1);m++)
        {
            dif +=m ;
        }
        n = sum - dif ;
        printf("Case %d: %d\n",i,n);
    }
    return 0;
}
