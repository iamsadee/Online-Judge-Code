#include<stdio.h>

int main()


{
    int arr[100] , N , T , i , j , mx , min ;
    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        for(j=1;j<=N;j++)
        {
            scanf("%d",&arr[j]);
        }

        mx = 0 ;
        min = 0 ;

        for(j=2;j<=N;j++)
        {
            if(arr[j-1]>arr[j])
            {
                min++;
            }
            else if(arr[j-1]<arr[j])
            {
                mx++;
            }
        }
        printf("Case %d: %d %d\n",i,mx,min);

    }
    return 0;
}
