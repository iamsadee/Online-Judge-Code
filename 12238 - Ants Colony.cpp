#include<bits/stdc++.h>
using namespace std;
struct A
{
    int x;
    long long val;
};
vector<A> node[100005];
int par[100005][18];
bool vis[100005];
long long dis[100005],d[100005];
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
            int z=node[y][i].x;
            if(vis[z]==0)
            {
                vis[z]=1;
                dis[z] =dis[y]+1;
                d[z] =d[y]+node[y][i].val;
                q.push(z);
                par[z][0]=y;
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
                //cout<<par[j][i]<<endl;
            }
            else par[j][i]=-1;
        }
        //cout<<endl;
    }
}
int query(int u,int v,int n)
{
    if(dis[u]<dis[v])
    {
        swap(u,v);
    }
    //cout<<u<<" "<<v<<endl;
    for(int j=log2(n); j>=0; j--)
    {
        if(dis[u] - (1 << j) >= dis[v])
        {
            u=par[u][j];
        }
    }
    //cout<<u<<" "<<v<<endl;
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
void clr(int n)
{
    for(int i=0; i<=n; i++)
    {
        //par[i][0]=-1;
        d[i]=0;
        dis[i]=0;
        vis[i]=0;
        node[i].clear();
    }
}
int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    int k=1;

    while(cin>>n)
    {
        if(n==0)
            break;
        clr(n);
        for(int i=1; i<n; i++)
        {
            int x;
            long long w;
            cin>>x>>w;
            A a,b;
            a.x=x;
            a.val=w;
            b.val=w;
            b.x=i;
            node[i].push_back(a);
            node[x].push_back(b);
        }
        memset(par,-1,sizeof par);
        bfs(0);
        //cout<<par[2][0]<<endl;
        sprash(n);
        int q;
        //cout<<"Case "<<k<<": "<<endl;
        k++;
        cin>>q;
        for(int i=1; i<=q; i++)
        {
            int u,v;
            cin>>u>>v;
            int res=query(u,v,n);
            //cout<<res<<endl;
            long long ans=d[u]+d[v]-2*d[res];
            //cout<<ans;
            if(i!=q)
                cout<<ans<<" ";
            else cout<<ans;
        }
        cout<<"\n";
    }
    return 0;
}
