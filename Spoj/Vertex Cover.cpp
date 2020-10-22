#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> node[100005];
int dp[100005][3];
bool vis[100005];
void dfs(int x)
{
    vis[x]=1;
    dp[x][0]=0;
    dp[x][1]=1;

    int n=node[x].size();
    for(int i=0; i<n; i++)
    {
        int y=node[x][i];
        if(vis[node[x][i]]==0){
            dfs(node[x][i]);
        dp[x][0] =dp[x][0]+ dp[y][1];
        dp[x][1] += min(dp[y][0],dp[y][1]);}
    }
    //cout<<"node "<<x<<endl;
}
int main()
{
    int n;
    cin>>n;
        for(int i=1; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        node[1].push_back(0);
        vis[0]=1;
        dfs(1);
        cout<<min(dp[1][1],dp[1][0])<<"\n";

    return 0;
}
