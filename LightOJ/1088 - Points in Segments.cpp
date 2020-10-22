#include<bits/stdc++.h>
using namespace std;
long long arr[100001];
long long binary(long long x,long long n)
{
    long long low , high , mid , ans;
    low = 1;
    high =n;
    ans =0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]<=x)
        {
            ans = mid;
            low = mid +1;
        }
        else
        {
            high = mid -1 ;
        }
    }
    return ans;
}
int main()
{
    long long n,q,t,i,j,k,x,y,ans,ans_1;
    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lld %lld",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        printf("Case %d:\n",j);
        for(i=1;i<=q;i++)
        {
           scanf("%lld %lld",&x,&y);
           ans = binary(x-1,n);
           ans_1=binary(y,n);
           printf("%lld\n",abs(ans-ans_1));
        }
    }
    return 0;
}
