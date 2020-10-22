#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> node[100005];
ll val[100005];
int par[100005][20];
//ll mx[100005][18];
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
            int z=node[y][i];
            if(vis[z]==0)
            {
                vis[z]=1;
                dis[z] =dis[y]+1;
                q.push(z);
                par[z][0]=y;
                //mx[z][0]=val[node[y][i]];
            }
        }
    }
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
                //mx[j][i]=min(mx[j][i-1],mx[par[j][i-1]][i-1]);
                //cout<<par[j][i]<<endl;
            }
            else
            {
                 par[j][i]=-1;
                 //mx[j][i]=mx[j][i-1];
            }
        }
        //cout<<endl;
    }
}
int query(int u,ll k,int n)
{
    int l=ceil(log2(n));
    for(int j=l;j>=0;j--)
    {
        if(par[u][j]!=-1)
        {
            int x=par[u][j];
            if(val[x]>=k)
            {
                u=par[u][j];
            }

        }
    }
    return u;
}

void clr(int n)
{
    for(int i=0; i<=n; i++)
    {
        //par[i][0]=-1;
        //p[i]=i;
        dis[i]=0;
        vis[i]=0;
        node[i].clear();
    }
}
int main()
{
    int n;
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int tc;
    //int k=1;
    scanf("%d",&tc);
    int q;
    for(int a=1;a<=tc;a++)
    {
        scanf("%d %d",&n,&q);
        clr(n);
        val[0]=1;
        for(int i=1;i<n;i++)
        {
            int x,y;
            ll w;
            scanf("%d %lld",&x,&w);
            val[i]=w;
            node[i].push_back(x);
            node[x].push_back(i);
        }
        memset(par,-1,sizeof par);
        //memset(mx,0,sizeof mx);
        bfs(0);
        sprash(n);

        printf("Case %d:\n",a);
        for(int i=1;i<=q;i++)
        {
            int u;
            ll val;
            scanf("%d %lld",&u,&val);
            printf("%d\n",query(u,val,n));
        }

    }


    return 0;
}
