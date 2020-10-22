#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[50005];
struct A
{
    int x;
    int val;
};
struct B
{
    int u,v;
    int cost;
};
vector<A> node[50005];
int par[50005][18],mx[50005][18];
bool vis[50005];
long long dis[50005];
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
                //cout<<par[j][i]<<endl;
            }
            else
            {
                 par[j][i]=-1;
                 mx[j][i]=mx[j][i-1];
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
        //par[i][0]=-1;
        p[i]=i;
        dis[i]=0;
        vis[i]=0;
        node[i].clear();
    }
}
B arr[100005];
bool cmp(B a,B b)
{
    return a.cost<b.cost;
}
int findd(int r)
{
    if(p[r]==r)
        return r;
    return p[r]=findd(p[r]);
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
void mst(int n,int m)
{
    sort(arr+1,arr+(m+1),cmp);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        //cout<<arr[i].w<<endl;
        int u=findd(arr[i].u);
        int v=findd(arr[i].v);
        //cout<<u<<" "<<v<<endl;
        if(u!=v)
        {
    //cout<<"sadee"<<endl;
            //cout<<arr[i].u<<" "<<arr[i].v<<" "<<arr[i].cost<<endl;
            p[u]=v;
            cnt++;
            A a,b;
            a.x=arr[i].v;
            a.val=arr[i].cost;
            b.x=arr[i].u;
            b.val=arr[i].cost;
            node[arr[i].u].push_back(a);
            node[arr[i].v].push_back(b);
            //cout<<cost<<endl;
            if(cnt==(n-1))
                break;
        }
    }
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
        scanf("%d %d",&n,&m);
        clr(n);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %d",&arr[i].u,&arr[i].v,&arr[i].cost);
        }
        memset(par,-1,sizeof par);
        memset(mx,0,sizeof mx);
        mst(n,m);
        bfs(1);
        sprash(n);
        int q;
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
            printf("%d\n",rs);
        }

    }


    return 0;
}
