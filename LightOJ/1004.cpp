/// LIGHT OJ - 1004(MONKEY Banana Probelm)
/// SOLVED

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> arr[210];
ll dp[210][210];
int n;
ll rec(int i,int j)
{
    if(i>(2*n-1) || j>=arr[i].size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll res=-1;
    if(j==0 && i>=n )
    {
        res =max(res,(arr[i][j]+rec(i+1,j)));
    }
    else if(j==(arr[i].size()-1) && i>=n)
    {
        res =max(res,(arr[i][j]+rec(i+1,j-1)));
    }
    else if(i<n)
    {
        res =max(res,(arr[i][j]+rec(i+1,j)));
        res =max(res,(arr[i][j]+rec(i+1,j+1)));
    }
    else
    {
        res =max(res,(arr[i][j]+rec(i+1,j)));
        res =max(res,(arr[i][j]+rec(i+1,j-1)));
    }
    return dp[i][j]=res;
}
int main()
{
    int i,j,k,t,b;
    ll a;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            arr[j].clear();
            for(k=1;k<=j;k++)
            {
                scanf("%lld",&a);
                arr[j].push_back(a);
            }
        }
        b=n+1;
        for(j=n-1;j>=1;j--)
        {
            arr[b].clear();
            for(k=1;k<=j;k++)
            {
                scanf("%lld",&a);
                arr[b].push_back(a);
            }
            b++;
        }
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n",i,rec(1,0));
    }
    return 0;
}
