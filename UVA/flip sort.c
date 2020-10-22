#include<stdio.h>
int main()
{
    int arr[1001],n,i,j,count,temp;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        count=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(arr[i]>arr[j])
                {
                    temp = arr[i];
                    arr[i]=arr[j];
                    arr[i]=temp;
                    count++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",count);
    }
    return 0;
}
