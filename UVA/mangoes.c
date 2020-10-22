#include<stdio.h>
int main()


{
    int T , N , L , mango[20] , i , j , k , l , mx , count , m ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&N,&L);

        for(j=1;j<=2*N;j++)
        {
            scanf("%d",&mango[j]);
        }
        count = 0 ;
        m = N+1 ;
        mx = 0;
        for(k=1;k<=N;k++)
        {
            mx += mango[k] ;

            if(mango[m] >= mango[k] )
            {
                count++ ;
            }
            m++;
        }

        if(L >= mx && count == N)
            printf("Case %d: Yes\n",i);
        else printf("Case %d: No\n",i);

    }
    return 0;
}
