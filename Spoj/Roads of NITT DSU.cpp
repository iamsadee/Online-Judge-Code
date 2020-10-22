#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[20005];
struct A
{
    char ch;
    int ID;
};
ll res[20005];
A qq[20005];
struct B
{
    int u,v;
};
B edge[20005];
ll par[20005];
ll sz[20005];
int findd(int x)
{
    if(par[x]==x)
        return x;
    return par[x]=findd(par[x]);
}
ll ans;
int n;
void unionn(int u,int v)
{
    int x=findd(u);
    int y=findd(v);
    if(x!=y)
    {
        if(sz[x]<sz[y])
            swap(x,y);

        par[y]=x;
        ans = ans - (sz[y]*sz[x]);
        //ans = ans - (sz[x]*abs(sz[x]-n));
        sz[x] += sz[y];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int a=1;a<=t;a++)
    {

        cin>>n;
        int m=n-1;
        int q;
        for(int i=1;i<=m;i++)
        {
            par[i]=i;
            sz[i]=1;
            int x,y;
            cin>>x>>y;
            edge[i].u=x;
            edge[i].v=y;
        }
        sz[n]=1;
        par[n]=n;
        cin>>q;
        ans=(n*(n-1))/2;
        for(int i=1;i<=q;i++)
        {
            char c;
            cin>>c;
            if(c=='Q')
            {
                qq[i].ch=c;
            }
            else
            {
                qq[i].ch=c;
                int x;
                cin>>x;
                mark[x]=true;
                qq[i].ID=x;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(mark[i]==false)
            {
                unionn(edge[i].u,edge[i].v);
            }
        }
        vector<ll> res;
        for(int i=q;i>=1;i--)
        {
            if(qq[i].ch=='Q')
            {
                res.push_back(ans);
            }
            else
            {
                int x=qq[i].ID;
                unionn(edge[x].u,edge[x].v);
            }
        }
        for(int i=res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
