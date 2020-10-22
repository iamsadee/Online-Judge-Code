#include<stdio.h>
int main()
{
    long long int a,i,j,n,sum,mx;
    while(scanf("%lld",&n)==1)
    {
        mx =0;
        sum=0;
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            sum += a ;
            if(mx<sum)
                mx = sum;
            if(sum<0)
            {
                sum=0;
            }
        }
        if(sum>0)
        {
            printf("The maximum winning streak is %lld.\n",mx);
        }
        else printf("Losing streak.\n");
    }
    return 0;
}
