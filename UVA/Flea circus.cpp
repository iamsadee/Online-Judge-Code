#include<bits/stdc++.h>
using namespace std;
vector<int> node[5005];
int par[5005][18];
bool vis[5005];
long long dis[5005];
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
            int z=node[y][i];
            if(vis[z]==0)
            {
                vis[z]=1;
                dis[z] =dis[y]+1;
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
int get(int x,int d)
{
    while(d!=0)
    {
        int z=log2(d);
        d -= (1<<z);
        x=par[x][z];
    }
    return x;
}
void clr(int n)
{
    for(int i=0; i<=n; i++)
    {
        //par[i][0]=-1;
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
            int x,y;
            long long w;
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        memset(par,-1,sizeof par);
        bfs(1);
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
            long long ans=dis[u]+dis[v]-2*dis[res];
            //cout<<ans;
            if(ans%2==0)
            {
                ans=ans/2;
                int x;
                int y=dis[u]-dis[res];
                if(ans<=y)
                {
                    x=get(u,ans);
                }
                else
                {
                    x=get(v,ans);
                }
                cout<<"The fleas meet at "<<x<<"."<<endl;
            }
            else
            {
                ans=ans/2;
                ans++;
                int a=dis[u]-dis[res];
                int b=dis[v]-dis[res];
                int x,y;
                if(ans<=a)
                {
                    y=get(u,ans);
                    x=get(u,ans-1);
                }
                else
                {
                    x=get(v,ans-1);
                    y=get(v,ans);
                }

                cout<<"The fleas jump forever between "<<min(x,y)<<" and "<<max(y,x)<<"."<<endl;
            }
        }
    }
    return 0;
}
