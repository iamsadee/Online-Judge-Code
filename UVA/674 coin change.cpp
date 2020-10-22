#include<bits/stdc++.h>
using namespace std;
int dp[6][7500];
int arr[]={1,5,10,25,50},amount,n;
int rec(int i,int sum)
{
    int res;
    if(i>=5)
        return 0;
    if(sum==0)
        return 1;
    else if(sum<0) return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    int res1=0,res2=0;
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
        printf("%d\n",rec(0,amount));
    }
    return 0;
}
