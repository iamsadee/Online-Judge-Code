#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
struct A
{
    int u,v;
    int w;
};
bool cmp(A x,A y)
{
    return x.w>y.w;
}
vector<A> arr;
vector<pair<int,ll> > node[20005];
int p[20005],dis[20005];
bool vis[20005];
int fnd(int x)
{
    if(p[x]==x)
    {
        return x;
    }
    return p[x]=fnd(p[x]);
}
int par[100005][18],mn[100005][18];
void mst()
{
    sort(arr.begin(),arr.end(),cmp);
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        int x=fnd(arr[i].u);
        int y=fnd(arr[i].v);
        if(x!=y)
        {
            cnt++;
            p[x]=y;
            node[arr[i].u].push_back({arr[i].v,arr[i].w});
            node[arr[i].v].push_back({arr[i].u,arr[i].w});
            if(cnt==(n-1))
            {
                break;
            }
        }
    }
}
void bfs(int x)
{
    vis[x]=1;
    queue<int> q;
    q.push(x);
    while(q.size()>0)
    {
        int y=q.front();
        q.pop();
        for(int i=0; i<node[y].size(); i++)
        {
            int z=node[y][i].first;
            if(vis[z]==0)
            {
                vis[z]=1;
                dis[z] =dis[y]+1;
                q.push(z);
                par[z][0]=y;
                mn[z][0]=node[y][i].second;
            }
        }
    }
}
void sprash(int n)
{
    int cnt=0;
    for(int i=1; (1<<i)<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(par[j][i-1]!=-1)
            {
                par[j][i]=par[par[j][i-1]][i-1];
                mn[j][i]=min(mn[j][i-1],mn[par[j][i-1]][i-1]);
            }
            else
            {
                 par[j][i]=-1;
                 mn[j][i]=mn[j][i-1];
            }
        }
    }
}
int query(int u,int v)
{
    if(dis[u]<dis[v])
    {
        swap(u,v);
    }
    for(int j=log2(n); j>=0; j--)
    {
        if(dis[u] - (1 << j) >= dis[v])
        {
            u=par[u][j];
        }
    }
    if(u!=v)
    {
        for(int j=log2(n); j>=0; j--)
        {
            if(par[u][j]!=par[v][j])
            {
                u=par[u][j];
                v=par[v][j];
            }
        }
        return par[u][0];
    }
    else return u;
}
int get(int x,int d)
{
    int res=1e8;
    while(d>0)
    {
        int b=log2(d);
        d -= (1<<b);
        res=min(res,mn[x][b]);
        x=par[x][b];
    }
    return res;
}

void clr()
{
    arr.clear();
    for(int i=1;i<=n;i++)
    {
        dis[i]=0;
        vis[i]=0;
        p[i]=i;
        node[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>n>>m>>q)
    {
        clr();
        for(int i=0;i<m;i++)
        {
            A a;
            cin>>a.u>>a.v>>a.w;
            arr.push_back(a);
        }
        mst();
        mn[1][0]=1e8;
        bfs(1);
        sprash(n);
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            int z=query(x,y);
            int c=dis[x]-dis[z];
            int b=dis[y]-dis[z];
            int rs=min(get(x,c),get(y,b));
            cout<<rs<<"\n";
        }
    }
    return 0;
}
