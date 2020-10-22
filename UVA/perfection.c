#include<stdio.h>
int main()
{
    long long int arr[101],i,j,k,l,sum;
    for(j=1;;j++)
    {
        scanf("%lld",&arr[j]);
        if(arr[j]==0)
            break;
    }
    printf("PERFECTION OUTPUT\n");
    for(i=1;i<j;i++)
    {
        sum=0;
        for(k=1;k<=arr[i]/2;k++)
        {
            if(arr[i]%k==0)
            {
                sum += k ;
            }
            if(sum>arr[i])
                break;
        }
        if(sum==arr[i])
        {
            if(arr[i]<10 )
            {
                printf("    %lld  PERFECT\n",arr[i]);
            }
            else if(arr[i]<100)
            {
                printf("   %lld  PERFECT\n",arr[i]);
            }
            else if(arr[i]<1000)
            {
                printf("  %lld  PERFECT\n",arr[i]);
            }
            else if(arr[i]<10000)
            {
                printf(" %lld  PERFECT\n",arr[i]);
            }
            else if(arr[i]<100000)
            {
                printf("%lld  PERFECT\n",arr[i]);
            }
        }
        else if(sum<arr[i])
        {
            if(arr[i]<10)
            {
                printf("    %lld  DEFICIENT\n",arr[i]);
            }
            else if(arr[i]<100)
            {
                printf("   %lld  DEFICIENT\n",arr[i]);
            }
            else if(arr[i]<1000)
            {
                printf("  %lld  DEFICIENT\n",arr[i]);
            }
            else if(arr[i]<10000)
            {
                printf(" %lld  DEFICIENT\n",arr[i]);
            }
            else if(arr[i]<100000)
            {
                printf("%lld  DEFICIENT\n",arr[i]);
            }
        }
        else if(sum>arr[i])
        {
             if(arr[i]<10)
            {
                printf("    %lld  ABUNDANT\n",arr[i]);
            }
            else if(arr[i]<100)
            {
                printf("   %lld  ABUNDANT\n",arr[i]);
            }
            else if(arr[i]<1000)
            {
                printf("  %lld  ABUNDANT\n",arr[i]);
            }
            else if(arr[i]<10000)
            {
                printf(" %lld  ABUNDANT\n",arr[i]);
            }
            else if(arr[i]<100000)
            {
                printf("%lld  ABUNDANT\n",arr[i]);
            }
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
