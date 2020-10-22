#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long arr[100001],n,m,mx,sum,low,high,mid,add,i,j,x,y;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        sum=0;
        mx=0;
        x=1000000000;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            sum += arr[i];
            if(mx<arr[i])
            {
                mx=arr[i];
            }
        }
        high = sum;
        low = mx;
        //y=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            /*if(mid==y)
                break;*/
            add=0;
            j=1;
            for(i=0;i<n;i++)
            {
                add+= arr[i];
                if(add>mid)
                {
                    j++;
                    if(add>mid)
                    {
                        add=arr[i];
                    }
                }
            }
            if(j<=m )
            {
                x=mid;
                high = mid-1;
                low = low;
            }
            else if(j>m)
            {
                low=mid+1;
                high = high;
            }
            //y=mid;
        }
        cout<<x<<endl;
    }
    return 0;
}
