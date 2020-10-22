#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<pair<int,int> >arr;
int fx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int x,y;
int vis[21][21];
int dis[21][21];
int pre[17][17];
bool valid(int x1,int y1)
{
    if(x1>n || x1<1 || y1>m || y1<1)
        return false;
    return true;
}
int bfs(int x1,int y1)
{
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=20; j++)
        {
            vis[i][j]=0;
            dis[i][j]=0;
        }
    }
    queue<int> q1,q2;
    q1.push(x1);
    q2.push(y1);
    vis[x1][y1]=1;
    while(q1.size()>0)
    {
        x1=q1.front();
        q1.pop();
        y1=q2.front();
        q2.pop();
        for(int i=0; i<8; i++)
        {
            int tmpx=x1+fx[i];
            int tmpy=y1+fy[i];
            if(valid(tmpx,tmpy))
            {
                //cout<<tmpx<<" "<<tmpy<<endl;
                if(vis[tmpx][tmpy]==0 )
                {
                    q1.push(tmpx);
                    q2.push(tmpy);
                    vis[tmpx][tmpy]=1;
                    dis[tmpx][tmpy]=dis[x1][y1]+1;
                }
            }
        }
    }
}
ll dp[33000][16];
int sz;
ll fun(int mask,int prev)
{
    if(mask==((1<<sz)-1))
    {
        return pre[prev][0];
    }
    if(dp[mask][prev]!=-1)
        return dp[mask][prev];
    ll res=1e18;
    for(int i=0; i<sz; i++)
    {
        int req=mask&(1<<i);
        if(req==0)
        {
            res=min(res,pre[prev][i+1]+fun((mask|(1<<i)),i+1));
        }
    }
    return dp[mask][prev]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>n>>m;
        arr.clear();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                char c;
                cin>>c;
                if(c=='x')
                {
                    x=i;
                    y=j;
                }
                else if(c=='g')
                {
                    arr.push_back(make_pair(i,j));
                }
            }
        }
        sz=arr.size();
        for(int i=0; i<sz; i++)
        {
            bfs(arr[i].first,arr[i].second);
            for(int j=0; j<sz; j++)
            {
                pre[i+1][j+1]=dis[arr[j].first][arr[j].second];
            }
            pre[0][i+1]=dis[x][y];
            pre[i+1][0]=dis[x][y];
        }
        memset(dp,-1,sizeof dp);
        ll res=fun(0,0);
        cout<<"Case "<<ks<<": "<<res<<"\n";

    }
    return 0;
}
