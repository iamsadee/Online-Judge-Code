#include<bits/stdc++.h>
using namespace std;
vector<int> node[105],ans[105];
//map<int,bool> mp[105];
int vis[105];
int l;
void dfs(int x)
{
    int i;
    for(i=0;i<node[x].size();i++)
    {
        int v=node[x][i];
        if(vis[v]==0)
        {
            vis[v]=1;
            dfs(v);
        }
    }
    return ;
}
void clr(int n)
{
    for(int i=1;i<=n;i++)
    {
        node[i].clear();
        ans[i].clear();
    }
}
int main()
{
    int n,i,j,q,k;
    while(scanf("%d",&n)==1)
    {
        clr(n);
        if(n==0)
            break;
        int x,y;
        while(cin>>x && x!=0)
        {
            while(cin>>y && y!=0)
            {
                node[x].push_back(y);
            }
        }
        for(l=1;l<=n;l++)
        {
            dfs(l);
            for(j=1;j<=n;j++)
            {
                if(vis[j]==0)
                {
                    ans[l].push_back(j);
                }
            }
            memset(vis,0,sizeof vis);
        }
        scanf("%d",&q);
        for(i=1;i<=q;i++)
        {
            scanf("%d",&x);
            printf("%d",ans[x].size());
            for(j=0;j<ans[x].size();j++)
            {
                printf(" %d",ans[x][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
