#include<stdio.h>

int main()

{
    int N , M , i , j,  k , cnt=0 ;
    while(scanf("%d %d",&N,&M)==2)
    {

        if( cnt == 1 ){
            printf("\n");
        }

        if(N<=M)
        {
            j = M-N+1 ;
            for(k=1;k<=j;k++)
             {
                printf("%d\n",++N);
             }
        }
        else if(N>=M)
        {
            j = N-M+1 ;
            for(i=1;i<=j;i++)
            {
                printf("%d\n",++M);
            }
        }
        cnt = 1 ;
    }
    return 0;
}
