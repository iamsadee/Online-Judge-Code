#include<bits/stdc++.h>
using namespace std;
int arr[24];
int dp[22][1000];
int n,m;
int fun(int i,int sum)
{
    if(i>=m)
        return 0;
    if(sum>n)
    return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    int res1=0,res2=0;
    if(sum+arr[i]<=n)
    {
        res1=arr[i]+fun(i+1,sum+arr[i]);
    }
    res2=fun(i+1,sum);
    if(res1>=res2)
    {
        return dp[i][sum]=res1;
    }
    else return dp[i][sum]=res2;
}
vector<int> ans;
void path(int i,int sum)
{
    if(i>=m)
        return ;
    if(sum>n)
        return;
    if((arr[i]+fun(i+1,sum+arr[i]))>fun(i+1,sum))
    {
        if(sum+arr[i]<=n){
            ans.push_back(i);
        path(i+1,sum+arr[i]);}
        else path(i+1,sum);
    }
    else path(i+1,sum);
}
int main()
{
    int i;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d",&arr[i]);
        }
        memset(dp,-1,sizeof dp);
        ans.clear();
        int x=fun(0,0);
        path(0,0);
        for(i=0;i<ans.size();i++)
        {
            printf("%d ",arr[ans[i]]);
        }
        printf("sum:%d\n",x);
    }
    return 0;
}
