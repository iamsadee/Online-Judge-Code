#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> node[30005];
int par[30005][18];
int dis[30005];
ll val[30005];
int vis[30005];
struct A
{
    int s,e;
};
A arr[30005];
int flag[60005];
int tt=0;
void dfs(int x,int p,int dep)
{
    //out<<x<<endl;
    dis[x]=dep;
    vis[x]=1;
    arr[x].s=++tt;
    par[x][0]=p;
    flag[tt]=val[x];
    //cout<<tt<<" "<<flag[tt]<<" "<<val[x]<<endl;
    for(int i=0; i<node[x].size(); i++)
    {
        int y=node[x][i];
        if(vis[node[x][i]]==0)
        {
            dfs(y,x,dep+1);
        }
    }
    arr[x].e=++tt;
    flag[tt]=val[x]*(-1);
}
void sprash(int n)
{
    int cnt=0;
    for(int i=1; (1<<i)<=n; i++)
    {
        for(int j=0; j<n; j++)
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
ll tree[300015];
void inti(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=flag[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    inti(left,b,mid);
    inti(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

///query work for i to j work

int que(int node,int b,int e, int i,int j)
{
    if(i>e ||j<b)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    ll res1=que(left,b,mid,i,j);
    ll res2=que(right,mid+1,e,i,j);
    return res1+res2;
}
/// update any value at any particular index
void update(int node,int b,int e,int i,int value,int rakha)
{
    if(i>e || i<b)
    {
        return ;
    }
    if(i<=b && i>=e)
    {
        if(rakha==0)tree[node]=value;
        else tree[node]=value*(-1);
        return;
    }
    int left=2*node;
    int right = 2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,value,rakha);
    update(right,mid+1,e,i,value,rakha);
    tree[node]=tree[left]+tree[right];
}
void clr(int n)
{
    memset(par,-1,sizeof par);
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        node[i].clear();
        dis[i]=0;

    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int q,n;
    for(int a=1; a<=t; a++)
    {
        scanf("%d",&n);
        clr(n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&val[i]);
        }
        for(int i=1; i<n; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            node[x].push_back(y);
            node[y].push_back(x);
        }
        tt=0;
        dfs(0,-1,0);
        sprash(n);
        inti(1,1,2*n);

        scanf("%d",&q);
        printf("Case %d:\n",a);
        for(int i=1;i<=q;i++)
        {
            int x;
            scanf("%d",&x);
            if(x==0)
            {
                int y,z;
                scanf("%d%d",&y,&z);
                int lca=query(y,z,n);
                //cout<<lca<<endl;
                //cout<<arr[lca].s<<" "<<arr[y].s<<" "<<arr[z].s<<endl;
                int res=que(1,1,2*n,arr[lca].s,arr[y].s);
                res =res+ que(1,1,2*n,arr[lca].s,arr[z].s);
                res = res - val[lca];
                printf("%d\n",res);
            }
            else
            {
                int y,z;
                scanf("%d%d",&y,&z);
                update(1,1,2*n,arr[y].s,z,0);
                update(1,1,2*n,arr[y].e,z,1);
                val[y]=z;

            }
        }
    }
    return 0;
}
