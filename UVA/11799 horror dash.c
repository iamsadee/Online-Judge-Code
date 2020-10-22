#include<stdio.h>
int main()

{
    int T , N , C[10000] , i , j ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int mx = 0 ;
        scanf("%d",&N);
        for(j=1;j<=N;j++)
        {
            scanf("%d",&C[j]);
            if(mx <= C[j])
            {
                mx = C[j];
            }
        }
        printf("Case %d: %d\n",i,mx);
    }

    return 0;
}
