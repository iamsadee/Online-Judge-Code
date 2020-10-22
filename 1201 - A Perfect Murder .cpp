#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> node[1005];
bool vis[1005];
int dp[2][1005];
void clr(int n)
{
    for(int i=0; i<=n; i++)
    {
        node[i].clear();
        vis[i]=0;
    }
}
int n,m;
void dfs(int x)
{
    dp[0][x]=0;
    dp[1][x]=1;
    vis[x]=1;
    int cnt=0;
    for(int i=0; i<node[x].size(); i++)
    {
        int y=node[x][i];
        if(vis[y]==0)
        {
            dfs(y);
            dp[1][x] += dp[0][y];
            dp[0][x] += max(dp[1][y],dp[0][y]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>n>>m;
        clr(n);
        for(int i=1; i<=m; i++)
        {
            int x,y;
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        ll ans=0;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                ans += max(dp[0][i],dp[1][i]);
            }
        }
        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
    return 0;
}
