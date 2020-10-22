#include<bits/stdc++.h>
using namespace std;
vector<int> node[10001];
vector<int> ans;
map<string,int> mp;
int c=0;
int vis[10001];
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
    int n , m ,i,j,t,k;
    string u,v;
    scanf("%d",&t);
    getchar();
    for(j=1;j<=t;j++)
    {
        scanf("%d",&m);
        k=1;
        for(i=1;i<=m;i++)
        {
            cin>>u>>v;
            if(mp[u]==0 )
            {
                mp[u]=k++;
            }
            if(mp[v]==0)
            {
                mp[v]=k++;
            }
            node[mp[u]].push_back(mp[v]);
        }
        for(i=1;i<=mp.size();i++)
        {
            if(vis[i]==0)
                dfs(i);
        }
        for(i=1;i<=mp.size();i++)
        {
            vis[i]=0;
            node[i].clear();
        }
        if(c==1)
            printf("Case %d: No\n",j);
        else{
                printf("Case %d: Yes\n",j);
        }
        c=0;
        ans.clear();
        mp.clear();
    }
    return 0;
}
