#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A
{
    int x;
    int val;
};
vector<A> node[100005];
int par[100005][18],mx[100005][18],mn[100005][18];
bool vis[100005];
long long dis[100005];
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
                q.push(z);
                par[z][0]=y;
                mx[z][0]=node[y][i].val;
                mn[z][0]=node[y][i].val;
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
                mx[j][i]=max(mx[j][i-1],mx[par[j][i-1]][i-1]);
                mn[j][i]=min(mn[j][i-1],mn[par[j][i-1]][i-1]);
                //cout<<par[j][i]<<endl;
            }
            else
            {
                 par[j][i]=-1;
                 mx[j][i]=mx[j][i-1];
                 mn[j][i]=mn[j][i-1];
            }
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

        dis[i]=0;
        vis[i]=0;
        node[i].clear();
    }
}
int get(int x,int d)
{
    int res=0;
    int ans=0;
    while(d>0)
    {
        int b=log2(d);
        d -= (1<<b);
        res=max(res,mx[x][b]);
        x=par[x][b];
    }
    return res;
}
int get1(int x,int d)
{
    int res=1e7;
    int ans=0;
    while(d>0)
    {
        int b=log2(d);
        d -= (1<<b);
        res=min(res,mn[x][b]);
        x=par[x][b];
    }
    return res;
}
int main()
{
    int n;
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int tc;
    int k=1;
    scanf("%d",&tc);
    int m;
    for(int a=1;a<=tc;a++)
    {
        scanf("%d",&n);
        clr(n);
        for(int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            A a,b;
            a.x=y;
            a.val=z;
            b.x=x;
            b.val=z;
            node[x].push_back(a);
            node[y].push_back(b);
        }
        //memset(par,-1,sizeof par);
        //memset(mx,0,sizeof mx);
        mn[1][0]=1e7;
        mx[1][0]=-1;
        bfs(1);
        sprash(n);
        int q;
        //cout<<mn[4][0]<<" "<<mn[2][0]<<endl;
        printf("Case %d:\n",a);
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            int z=query(x,y,n);
            int c=dis[x]-dis[z];
            int b=dis[y]-dis[z];
            int rs=max(get(x,c),get(y,b));
            int rs1=min(get1(x,c),get1(y,b));
            //cout<<get(x,c)<<" "<<get1(y,b)<<endl;
            //cout<<x<<" "<<y<<" "<<c<<endl;
            printf("%d %d\n",rs1,rs);
        }

    }


    return 0;
}
