#include<bits/stdc++.h>
using namespace std;

int cost[1001],w[1001],dp[1001][31],n,weight;
int rec(int i,int sum)
{
    int res1=0,res2=0;
    if(i >= n+1) return 0;
    //if(sum==weight) return 1;
    //else if(sum>weight) return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(sum+w[i]<=weight)
        res1 = cost[i]+rec(i+1,sum+w[i]);
    res2 = rec(i+1,sum);

    return dp[i][sum]=max(res1,res2);
}

int main()
{
    int t,i,j,m;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d %d",&cost[j],&w[j]);
        }
        scanf("%d",&m);
        int a=0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&weight);
            memset(dp,-1,sizeof dp);
            a += rec(1,0);
        }
        printf("%d\n",a);
    }
    return 0;
}
