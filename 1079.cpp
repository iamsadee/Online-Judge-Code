#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[105][10005];
bool vis[105][10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1;ks<=t;ks++)
    {
        double p;
        int n;
        cin>>p>>n;
        double pr[n+2];
        int arr[n+2];
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i]>>pr[i];
            sum += arr[i];
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                vis[i][j]=0;
                dp[i][j]=1e9;
            }
        }
        vis[0][0]=1;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(vis[i-1][j]==1)
                {
                    int req=j+arr[i];
                    dp[i][req]=min(dp[i][req],dp[i-1][j]+((1.0-dp[i-1][j])*pr[i]));
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
                    vis[i][req]=1;
                    vis[i][j]=1;
                }
            }
        }
        int res=0;
        for(int i=0;i<=sum;i++)
        {
            //printf("%d %0.5lf\n",i,dp[n][i]);
            if(dp[n][i]<p) res=i;
        }
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
