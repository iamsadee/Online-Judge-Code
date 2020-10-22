#include<stdio.h>
int main()


{
    int T , N , arr[20],i , j ,k,temp,x;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        for(j=1;j<=N;j++)
        {
            scanf("%d",&arr[j]);
        }

        for(j=1;j<=N;j++)
        {
            k= j ;
            while(k>1 && arr[k-1]>arr[k])
            {
                temp  = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = temp;
                k--;

            }
        }
        x = N/2 + 1;
        printf("Case %d: %d\n",i,arr[x]);

    }
    return 0;
}
