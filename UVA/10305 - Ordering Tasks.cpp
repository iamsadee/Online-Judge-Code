#include<bits/stdc++.h>
using namespace std;
vector<int> node[101];
vector<int> ans;
int vis[101];
void dfs(int x)
{
    vis[x]=1;
    int i,y;
    for(i=0;i<node[x].size();i++)
    {
        y=node[x][i];
        if(vis[y]==0)
            dfs(y);
    }
    ans.push_back(x);
    vis[x]=-1;
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
        for(i=ans.size()-1;i>=0;i--)
        {
            printf("%d",ans[i]);
            if(i==0)
                printf("\n");
            else printf(" ");
        }
        ans.clear();
    }
    return 0;
}
