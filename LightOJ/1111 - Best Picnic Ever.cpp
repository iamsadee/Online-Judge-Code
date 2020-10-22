#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll al[100005];
bool vis[1005];
//int cnt=0;
vector<int> node[1005];
map<int,int> mp;
map<int,int> ::iterator it;
void dfs(int src)
{
    if(vis[src]==1)
        return ;
    vis[src]=1;
    mp[src] +=1;
    int i;
    for(i=0;i<node[src].size();i++)
    {
        int y=node[src][i];
        if(vis[y]==0)
        {
            //cnt++;
            dfs(y);
        }
    }
}
void clr(int n)
{
    for(int i=1;i<=n;i++)
    {
        node[i].clear();
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m,k;
        scanf("%d %d %d",&k,&n,&m);
        clr(n);
        int arr[105];
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(int j=1;j<=m;j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            node[x].push_back(y);
        }
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            memset(vis,0,sizeof vis);
            dfs(arr[j]);
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            //cout<<(*it).second<<endl;
            if((*it).second==k )
            {

                ans++;
            }
        }
        mp.clear();
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
