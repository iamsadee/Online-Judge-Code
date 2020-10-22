#include<bits/stdc++.h>
using namespace std;
int arr[105],m,amo;
int dp[105][50005];
int fun(int i,int sum)
{
    if(i==m) return 0;
    if(sum<0)
        return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    int res1=0,res2=0;
    if(sum-arr[i]>=0)res1 = arr[i]+fun(i+1,sum-arr[i]);
    res2 = fun(i+1,sum);
    return dp[i][sum]=max(res1,res2);
}
int main()
{
    int n,i,j,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        sum=0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[j]);
            sum += arr[j];
        }
        memset(dp,-1,sizeof dp);
        sort(arr,arr+m);
        amo=sum/2;
        int ans=fun(0,amo);
        //cout<<ans<<endl;
        int y=sum-ans;
        printf("%d\n",abs((y-ans)));
    }
    return 0;
}
