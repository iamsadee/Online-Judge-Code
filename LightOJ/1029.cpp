#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int par[10005];

struct graph
{
    int u,v,w;
};
bool comp(graph x,graph y)
{
    return x.w<y.w;
}
graph arr[10005];
int findd(int r)
{
    if(par[r]==r)
        return r;
    return par[r]=findd(par[r]);
}
int mst(int n,int m)
{
    sort(arr+1,arr+(m+1),comp);
    for(int i=1; i<=n+1; i++)
    {
        par[i]=i;
    }
    ll cost=0;
    int count=0;
    for(int i=1; i<=m; i++)
    {
        //cout<<arr[i].w<<endl;
        int u=findd(arr[i].u);
        int v=findd(arr[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            cost += arr[i].w;
            //cout<<cost<<endl;
            if(count==(n))
                break;
        }
    }
    return cost;
}
int mst_1(int n,int m)
{
    for(int i=1; i<=n+1; i++)
    {
        par[i]=i;
    }
    ll cost=0;
    int count=0;
    for(int i=m; i>=1; i--)
    {
        //cout<<arr[i].w<<endl;
        int u=findd(arr[i].u);
        int v=findd(arr[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            cost += arr[i].w;
            //cout<<cost<<endl;
            if(count==(n))
                break;
        }
    }
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        cin>>n;
        m=0;
        int x,y,z;
        while(1)
        {
            cin>>x>>y>>z;
            if(x==0 && y==0 && z==0)
                break;
            m++;
            arr[m].u=x+1;
            arr[m].v=y+1;
            arr[m].w=z;

        }
        ll cost_min=mst(n,m);
        cost_min += mst_1(n,m);
        if(cost_min%2==0)
        {
            cout<<"Case "<<i<<": ";
            cout<<cost_min/2<<'\n';
        }
        else
        {
            cout<<"Case "<<i<<": "<<cost_min<<'/'<<'2'<<'\n';
        }
        i++;
    }
    return 0;
}
