#include<stdio.h>
int main()
{
    static long long int N , M , i ,j,n,low,high,med, arr[1000001] , ar[1000001],x,count;
    while(scanf("%lld %lld",&N,&M)==2)
    {
        if(N==0 && M==0)
            break;
        count = 0;
        for(i=1;i<=N;i++)
        {
            scanf("%lld",&arr[i]);
        }
        for(i=1;i<=M;i++)
        {
            scanf("%lld",&ar[i]);
        }
        if(M>=N)
        {
            for(i=1;i<=N;i++)
            {
                x = arr[i] ;
                low=1;
                high = M ;
                while(low<=high)
                {
                    med = (low+high)/2 ;
                    if(ar[med]>x)
                    {
                        high = med-1 ;
                        low = low ;
                        n=0;
                    }
                    else if(ar[med]<x)
                    {
                        low = med+1;
                        high = high ;
                        n=0 ;
                    }
                    else if(ar[med]==x)
                    {
                        high = high-1;
                        low = low;
                        n=1;
                    }
                }
                count+=n ;
            }
        }
        else if(N>=M)
        {
            for(i=1;i<=M;i++)
            {
                x = ar[i] ;
                low=1;
                high = N ;
                while(low<=high)
                {
                    med = (low+high)/2 ;
                    if(arr[med]>x)
                    {
                        high = med-1 ;
                        low = low ;
                        n=0;
                    }
                    else if(arr[med]<x)
                    {
                        low = med+1;
                        high = high ;
                        n=0 ;
                    }
                    else if(arr[med]==x)
                    {
                        high = high-1;
                        low = low;
                        n=1;
                    }
                }
                count += n ;
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
