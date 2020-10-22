#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A
{
    int v;
    int val;
};
vector<A> node[30005];
bool vis[30005];
int d[30005];
void clr(int n)
{
    memset(d,0,sizeof d);
    memset(vis,0,sizeof vis);
    for(int i=0;i<=n;i++)
    {
        node[i].clear();
    }
}
struct B
{
    int v;
    int mx1,mx2,best;
};
B arr[30005];
int mx=0;
void dfs(int x)
{
    vis[x]=1;
    if(node[x].size()==1)
    {
        arr[x].mx1=0;
        return ;
    }
    vector<int> ans;
    for(int i=0;i<node[x].size();i++)
    {
        int y=node[x][i].v;
        if(vis[y]==0)
        {
            dfs(y);
            ans.push_back(node[x][i].val+arr[y].mx1);
        }
    }
    sort(ans.begin(),ans.end());
    arr[x].mx1=ans[ans.size()-1];
    arr[x].best=arr[x].mx1;
    if(ans.size()>1)
    {
        arr[x].mx2=ans[ans.size()-2];
        arr[x].best +=arr[x].mx2;
    }
    mx=max(arr[x].best,mx);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int n;
        scanf("%d",&n);
        clr(n);
        A a;
        a.v=30003;
        a.val=0;
        vis[30003]=1;
        node[0].push_back(a);
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            A a;
            A b;
            a.v=u;
            a.val=w;
            b.v=v;
            b.val=w;
            node[u].push_back(b);
            node[v].push_back(a);
        }
        memset(arr,0,sizeof arr);
        mx=0;
        dfs(0);
        printf("Case %d: %d\n",k,mx);


    }

    return 0;
}
