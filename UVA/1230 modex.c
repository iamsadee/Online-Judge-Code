#include<stdio.h>
int main()
{
    long long int x,y,n,a,i,j,k,arr[100000],d,pow,re;
    scanf("%lld",&a);
    for(i=0;i<=a;i++)
    {
        scanf("%lld",&x);
        if(x==0)
            break;
        scanf("%lld %lld",&y,&n);
        j=0;
        d=y;
        while(d!=0)
        {
            arr[j]=d%2;
            d=d/2;
            j++;
        }
        re=1;
        pow = x%n;
        for(k=0;k<j;k++)
        {
            if(arr[k]==1)
            {
                re=(re*pow)%n;
            }
            pow = (pow*pow)%n;
        }
        printf("%lld\n",re);
    }
    return 0;
}
