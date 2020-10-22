
#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[102][102];
long long fun(int i,int sum)
{
    if(i>k)
        return 0;
    if(sum>n)
        return 0;
    if(sum==n && i==k)
        return 1;
    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }
    int res=0;
    for(int j=0;j<=n;j++)
    {
        res +=fun(i+1,sum+j);
    }
    return dp[i][sum]=res%1000000;

}
int main()
{
    while(scanf("%d %d",&n,&k)==2)
    {
        if(n==0 && k==0)
            break;
        memset(dp,-1,sizeof dp);
        long long ans;
        ans = fun(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
