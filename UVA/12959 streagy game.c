#include<stdio.h>
int main()

{
    long long int i,j ,J , R , arr[501] ,mx,a,n;
    while(scanf("%lld %lld",&J,&R)==2)
    {
        mx=0;
        for(i=0;i<=R;i++)
        {
            for(j=1;j<=J;j++)
            {
                if(i==0)
                {
                    arr[j]=0;
                }
                else
                {
                    scanf("%lld",&a);
                    arr[j]+=a;
                    if(mx<=arr[j])
                    {
                        mx = arr[j];
                        n = j;
                    }
                }
            }
        }
        printf("%lld\n",n);
    }
    return 0;
}
