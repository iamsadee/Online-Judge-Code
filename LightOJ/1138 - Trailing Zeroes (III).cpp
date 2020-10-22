#include<bits/stdc++.h>
using namespace std;
long long binary(long long q)
{
    long long high,low,mid,ans,n,res;
    ans=-1;
    low=0;
    high=1000000002;
    while(low<=high)
    {
        mid=(low+high)/2;;
        n=mid;
        res=0;
        while(n>=5)
        {
            res += n/5 ;
            n=n/5;
        }
        if(res==q)
        {
            ans=mid;
            high=mid-1;
        }
        else if(res<q)
        {
            low=mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}
int main()
{
    long long t,i,q,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&q);
        ans=binary(q);
        if(ans==-1)
        {
            printf("Case %lld: impossible\n",i);
        }
        else printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
