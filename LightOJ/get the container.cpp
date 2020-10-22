#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t , i , j , k, n , arr[1001],m,sum,low ,high , mid,chk,ans;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        k=0;
        scanf("%lld %lld",&n,&m);
        sum =0;
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
            k=max(k,arr[j]);
            sum += arr[j];
        }
        low=k;
        high = sum;
        while(low<=high)
        {
            mid = (low + high)/2;
            sum=0;
            chk=1;
            for(j=1;j<=n;j++)
            {
                sum += arr[j];
                if(sum>mid)
                {
                    sum =arr[j];
                    chk++;
                }
            }
            if(chk<=m)
            {
                ans=mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
