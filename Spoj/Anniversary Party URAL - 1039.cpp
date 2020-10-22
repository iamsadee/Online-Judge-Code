#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cost[6005];
ll dp[6005][3];
ll vis[6005];
vector<int> node[6005];
void fun(int x)
{
    vis[x]=1;
    dp[x][0]=0;
    dp[x][1]=cost[x];
    for(int i=0;i<node[x].size();i++)
    {
        int y=node[x][i];
        if(vis[y]==0)
        {
            fun(y);
            dp[x][0] += max(dp[y][1],dp[y][0]);
            dp[x][1] += (dp[y][0]);
        }
    }


}
void clr()
{
    for(int i=1;i<=6000;i++)
    {
        node[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n)
    {
        clr();
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i];
        }
        ll x=-1,y=-1;
        ll mx=0;
        int vertex=1;
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        while(1)
        {
            cin>>x>>y;
            if(x==0 && y==0 )
                break;
            node[x].push_back(y);
            node[y].push_back(x);
            if(mx<node[x].size())
            {
                mx=node[x].size();
                vertex=x;
            }
            if(mx<node[y].size())
            {
                mx=node[y].size();
                vertex=y;
            }
        }
        fun(vertex);
        ll ans = max(dp[vertex][0],dp[vertex][1]);
        cout<<ans<<"\n";


    }

    return 0;
}
