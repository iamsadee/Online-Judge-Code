#include<bits/stdc++.h>
using namespace std;
int arr[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
long long dp[22][10001],amount;
long long rec(int i,int sum)
{
    if(i>=21) return 0;
    if(sum==0)
        return 1;
    else if(sum<0)
        return 0;
    long long res1=0,res2=0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(sum-arr[i]>=0)
    {
        res1=rec(i,sum-arr[i]);
    }
    res2=rec(i+1,sum);
    return dp[i][sum]=res2+res1;

}
int main()
{
    memset(dp,-1,sizeof dp);
    while(scanf("%lld",&amount)==1)
    {
        printf("%lld\n",rec(0,amount));
    }
    return 0;
}
