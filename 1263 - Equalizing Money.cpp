#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> node[1005];
bool vis[1005];
int arr[1005];
void clr()
{
    for(int i=0;i<=1000;i++)
    {
        node[i].clear();
        vis[i]=0;
    }
}
ll ans=0;
int cnt=0;
void dfs(int x)
{
    cnt++;
    ans += arr[x];
    vis[x]=1;
    for(int i=0;i<node[x].size();i++)
    {
        int y=node[x][i];
        if(vis[y]==0)
        {
            dfs(y);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        clr();
        int n,m;
        scanf("%d %d",&n,&m);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(int j=0;j<m;j++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            node[u].push_back(v);
            node[v].push_back(u);
        }
        set<ll> st;
        bool chk=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0)
            {
                ans=0;
                cnt=0;
                dfs(j);
                if(ans%cnt!=0)
                {
                    chk=1;
                }
                else st.insert(ans/cnt);
            }
        }
        if(chk==1)
            printf("Case %d: No\n",i);
        else
        {
            if(st.size()==1)
                printf("Case %d: Yes\n",i);
            else printf("Case %d: No\n",i);
        }
    }
    return 0;

}
