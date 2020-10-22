#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> node[105];
bool vis[105];
int d2[105],d1[105];
void bfs(int s)
{
    vis[s]=1;
    queue<int> q;
    q.push(s);
    d1[s]=0;
    vis[s]=1;
    while(q.size()>0)
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<node[x].size();i++)
        {
            int y=node[x][i];
            if(vis[y]==0)
            {
                vis[y]=1;
                q.push(y);
                d1[y] = d1[x]+1;
            }
        }
    }
}
void bfs1(int s)
{
    vis[s]=1;
    queue<int> q;
    q.push(s);
    d2[s]=0;
    vis[s]=1;
    while(q.size()>0)
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<node[x].size();i++)
        {
            int y=node[x][i];
            if(vis[y]==0)
            {
                vis[y]=1;
                q.push(y);
                d2[y] = d2[x]+1;
            }
        }
    }
}
void clr(int n)
{
    memset(d1,0,sizeof vis);
    memset(d2,0,sizeof vis);
    memset(vis,0,sizeof vis);
    for(int i=0;i<=n;i++)
    {
        node[i].clear();
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        clr(n);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            node[x].push_back(y);
            node[y].push_back(x);
        }
        int s,d;
        scanf("%d %d",&s,&d);
        bfs(s);
        memset(vis,0,sizeof vis);
        bfs1(d);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int r=d1[i]+d2[i];
            ans=max(ans,r);
        }
        printf("Case %d: %d\n",a,ans);
    }


    return 0;
}
