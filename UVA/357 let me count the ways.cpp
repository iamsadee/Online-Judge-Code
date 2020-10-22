#include<bits/stdc++.h>
using namespace std;
long long dp[6][30001];
int arr[]={1,5,10,25,50},amount,n;
long long rec(int i,int sum)
{
    int res;
    if(i>=5)
        return 0;
    if(sum==0)
        return 1;
    else if(sum<0) return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    long long res1=0,res2=0;
    if(sum-arr[i]<=amount)
        res1=rec(i,sum-arr[i]);
    res2=rec(i+1,sum);
    return dp[i][sum]=res1+res2;
}
int main()
{
    int i;
     memset(dp,-1,sizeof dp);
    while(scanf("%d",&amount)==1)
    {
        long long y=rec(0,amount);
        if(y==1)
            printf("There is only 1 way to produce %d cents change.\n",amount);
        else printf("There are %lld ways to produce %d cents change.\n",y,amount);
    }
    return 0;
}
