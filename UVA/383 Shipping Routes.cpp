#include<bits/stdc++.h>
using namespace std;
vector<string> node[100];
map<string,int> mp,dis,vis;
map<string,int>:: iterator it;
int bfs(string ch,string ar)
{
    dis.clear();
    vis.clear();
    int x,y,i,j,a,b;
    string name,nam;
    queue<string> line;
    line.push(ch);
    dis[ch]=0;
    vis[ch]=1;
    while(line.size()>0)
    {
        name=line.front();
        y=mp[name];
        x=node[y].size();
        for(i=0;i<x;i++)
        {
            nam=node[y][i];
            if(vis[nam]==0)
            {
                vis[nam]=1;
                line.push(nam);
                dis[nam]=dis[name]+1;
            }
        }
        line.pop();
    }
}
int main()
{
    int m,n,p,i,j,x,y,t;
    string ch,ar;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d %d %d",&m,&n,&p);
        for(i=1;i<=m;i++)
        {
            cin>>ch;
            mp[ch]=i;
        }
        for(i=0;i<n;i++)
        {
            cin>>ch>>ar;
            node[mp[ch]].push_back(ar);
            node[mp[ar]].push_back(ch);
        }
        if(j==1)
        {
            printf("SHIPPING ROUTES OUTPUT\n\n");
        }
        printf("DATA SET  %d\n\n",j);
        for(i=1;i<=p;i++)
        {
            scanf("%d ",&x);
            cin>>ch>>ar;
            bfs(ch,ar);
            if(dis[ar]==0)
            {
                printf("NO SHIPMENT POSSIBLE\n");
            }
            else
            {
                y=dis[ar]*x*100;
                printf("$%d\n",y);
            }
        }
        printf("\n");
        for(i=1;i<=31;i++)
        {
            node[i].clear();
        }
        mp.clear();
    }
    printf("END OF OUTPUT\n");
    return 0;
}
