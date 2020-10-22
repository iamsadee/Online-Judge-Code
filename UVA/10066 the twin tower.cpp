#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101],b[101],n,m,dp[101][101];
int fun(int i,int j)
{
    if(i==n || j==m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int res=0,res1,res2;
    if(a[i]==b[j])
    {
        res = 1+(fun(i+1,j+1));
    }
    else{
    res1 = fun(i+1,j);
    res2 = fun(i,j+1);
    res = max(res1,res2);
    }
    return dp[i][j]=res;
}
int main()
{
    int i,j,k=1;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        memset(dp,-1,sizeof dp);
        int ans = fun(0,0);
        printf("Twin Towers #%d\n",k++);
        printf("Number of Tiles : %d\n\n",ans);
    }
    return 0;
}
