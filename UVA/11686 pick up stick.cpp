#include<bits/stdc++.h>
using namespace std;
vector<int> node[100001];
vector<int> ans;
int c=0;
int vis[100001];
void dfs(int x)
{
    if(c==1) return ;
    vis[x]=1;
    int i,y;
    for(i=0;i<node[x].size();i++)
    {
        y=node[x][i];
        if(vis[y]==0)
            dfs(y);
        if(vis[y]==1)
        {
            c=1;
            dfs(y);
        }
    }
    ans.push_back(x);
    vis[x]=2;
    return ;
}
int main()

{
    int n , m ,u,v,i,j;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0)
            break;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&u,&v);
            node[u].push_back(v);
        }
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
                dfs(i);
        }
        for(i=1;i<=n;i++)
        {
            vis[i]=0;
            node[i].clear();
        }
        if(c==1)
            printf("IMPOSSIBLE\n");
        else{
        for(i=ans.size()-1;i>=0;i--)
        {
            printf("%d\n",ans[i]);
        }
        }
        c=0;
        ans.clear();
    }
    return 0;
}
