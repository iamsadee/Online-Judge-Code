#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int,int> > node[30005];
ll pre[30005];
bool vis[30005];
ll ans[30005];
void clr()
{
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
        vis[i]=0;
        node[i].clear();
        pre[i]=0;
    }
}
void dfs(int x,int wt)
{
    vis[x]=1;
    pre[x]=wt;
    ll mx=0;
    for(int i=0;i<node[x].size();i++)
    {
        int y=node[x][i].first;
        int w=node[x][i].second;
        if(vis[y]==0)
        {
            dfs(y,wt+w);
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int ks=1;ks<=t;ks++)
    {
        scanf("%d",&n);
        clr();
        //vis[30000]=1;
        //node[0].push_back(make_pair(30000,0));
        for(int i=1;i<n;i++)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            node[x].push_back(make_pair(y,w));
            node[y].push_back(make_pair(x,w));
        }
        dfs(0,0); /// Find distance from 0 to all nodes
        int id=-1;
        ll mx=-1;
        for(int i=0;i<n;i++)
        {
            if(mx<pre[i])
            {
                mx=pre[i];
                id=i;
            }
        }
        ll dist1[30005];
        memset(vis,0,sizeof vis);
        memset(pre,0,sizeof pre);
        dfs(id,0); /// find 1st max distance node & get distance from it
        id=-1;
        mx=-1;
        for(int i=0;i<n;i++)
        {
            dist1[i]=pre[i];
            //cout<<pre[i]<<endl;
            if(mx<pre[i])
            {
                mx=pre[i];
                id=i;
            }
        }
        memset(vis,0,sizeof vis);
        memset(pre,0,sizeof pre);
        dfs(id,0); /// 2nd max distance node & get distance from it
        for(int i=0;i<n;i++)
        {
            ans[i]=max(dist1[i],pre[i]);
        }
        printf("Case %d:\n",ks);
        for(int i=0;i<n;i++)
        {
            printf("%lld\n",ans[i]);
        }
    }
    return 0;
}
