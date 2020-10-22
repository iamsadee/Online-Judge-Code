#include<bits/stdc++.h>
using namespace std;
int arr[21][4],n,dp[21][4];
int rec(int i,int j)
{
    if(i>n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int res=100000;
    if(j==1)
    {
        res = min(res,(arr[i][j]+rec(i+1,j+1)));
        res = min(res,(arr[i][j]+rec(i+1,j+2)));
    }
    else if(j==2)
    {
        res = min(res,(arr[i][j]+rec(i+1,j-1)));
        res = min(res,(arr[i][j]+rec(i+1,j+1)));
    }
    else if(j==3)
    {
        res = min(res,(arr[i][j]+rec(i+1,j-1)));
        res = min(res,(arr[i][j]+rec(i+1,j-2)));
    }
    return dp[i][j]=res;
}
int main()
{
    int t,i,j,k,a;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=3;k++)
            {
                scanf("%d",&arr[j][k]);
            }
        }
        memset(dp,-1,sizeof dp);
        a=rec(1,1);
        memset(dp,-1,sizeof dp);
        a=min(a,rec(1,2));
        memset(dp,-1,sizeof dp);
        a=min(a,rec(1,3));
        printf("Case %d: %d\n",i,a);
    }
    return 0;
}
