#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long arr[50001],i,j,x,q,n,a,b,c,d;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    scanf("%lld",&q);
    for(i=0;i<q;i++)
    {
        scanf("%lld",&x);
        a=0;
        b=0;
        c=0;
        d=0;
        for(j=0;j<n;j++)
        {
            if(arr[j]>x && j==0)
            {
                b=arr[j];
                c=1;
                d=1;
                break;
            }
            else if(arr[j]<x && j==n-1)
            {
                a=arr[j];
                c=1;
                d=1;
                break;
            }
            else if(arr[j]>x )
            {
                c=1;
                d=1;
                b=arr[j];
                break;
            }
        }
        if(j==n)
        {
            j=j-1;
        }
        while(arr[j]>=x && j>=0)
                {
                    j--;
                    a=arr[j];
                }
        if(a>=x)
        {
            a=0;
        }
        if(a>0 && b>0)
            printf("%lld %lld\n",a,b);
        else if(a==0 && b>0)
            printf("X %lld\n",b);
        else if(a>0 && b==0)
            printf("%lld X\n",a);
        else if(a==0 && b==0)
        {
            printf("X X\n");
        }
    }
    return 0;
}
