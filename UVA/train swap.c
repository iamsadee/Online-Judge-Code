#include<stdio.h>
int main()


{
    int T , i , L , arr[1000],j,k,count,temp;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&L);
        for(j=1;j<=L;j++)
        {
            scanf("%d",&arr[j]);
        }
        count = 0 ;

    for(k=1;k<=L;k++)
    {
        j=k;
        while(j>1 && arr[j-1]>arr[j])
        {
            temp  = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
            count++;
        }
    }

    printf("Optimal train swapping takes %d swaps.\n",count);

    }
    return 0;
}
