#include<stdio.h>
#include<math.h>
int prime(long long int n)
{
    int i,x;
    x=sqrt(n);
    if(n==1 || n==0)
        return 0;
    for(i=2;i<=x;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    long long int a,b,i,j,k,n ,arr[100000],x;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        if(n==1)
            printf("1 =\n");
        else if(n==-1)
            printf("-1 = -1\n");
    else if(n<0)
        {
            n=n*(-1);
            x=-1*n;
            if(prime(n))
                printf("-%lld = -1 x %lld\n",n,n);
            else
            {
                j=0;
                while(!prime(n))
                {
                    for(i=2;i<=n/2;i++)
                    {
                        if(n%i==0 && prime(i))
                        {
                            arr[j]=i;
                            n=n/i;
                            j++;
                            break;
                        }
                    }
                }
                arr[j]=n;
                j++;
                printf("%lld = -1 x ",x);
                for(k=0;k<j;k++)
                {
                    printf("%lld",arr[k]);
                    if(k<j-1)
                    {
                        printf(" x ");
                    }
                    else printf("\n");
                }
            }
        }
        else if(n>0)
        {
            x=n;
            if(prime(n))
                printf("%lld = %lld\n",n,n);
            else
            {
                j=0;
                while(!prime(n))
                {
                    for(i=2;i<=n/2;i++)
                    {
                        if(n%i==0 && prime(i))
                        {
                            arr[j]=i;
                            n=n/i;
                            j++;
                            break;
                        }
                    }
                }
                arr[j]=n;
                j++;
                printf("%lld = ",x);
                for(k=0;k<j;k++)
                {
                    printf("%lld",arr[k]);
                    if(k<j-1)
                    {
                        printf(" x ");
                    }
                    else printf("\n");
                }
            }
        }
    }
    return 0;
}
