#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;
        scanf("%d",&n);
        int cost[105][105];
        vector<int> node[105];
        deque<int> d1,d2;
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            node[x].push_back(y);
            node[y].push_back(x);
            cost[x][y]=0;
            cost[y][x]=z;
        }
        int x=1;
        bool vis[105];
        memset(vis,0,sizeof vis);
        vis[x]=1;
        d1.push_back(x);
        d2.push_back(x);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<node[x].size();j++)
            {
                int y=node[x][j];
                if(vis[y]==0)
                {
                    vis[y]=1;
                    x=y;
                    d1.push_back(y);
                    d2.push_back(y);
                    break;
                }
            }
        }
        //cout<<d1.size()<<" "<<d2.size()<<endl;
        d1.push_back(1);
        d2.push_back(1);
        int ans1=0,ans=0;
        x=d1.front();
        d1.pop_front();
        while(d1.size()>0)
        {
            int y=d1.front();
            d1.pop_front();
            ans += cost[x][y];
            x=y;
        }
        //cout<<ans<<endl;
        x=d2.back();
        //cout<<x<<endl;
        d2.pop_back();
        while(d2.size()>0)
        {
            int y=d2.back();
            d2.pop_back();
            ans1 += cost[x][y];
            x=y;
        }
        int mn=min(ans,ans1);
        printf("Case %d: %d\n",a,mn);



    }


    return 0;
}
