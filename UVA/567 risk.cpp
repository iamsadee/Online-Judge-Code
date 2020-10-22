#include<bits/stdc++.h>
using namespace std;
vector<int>node[1000];
int vis[1000],dis[1000];
int bfs(int a,int b)
{
    queue<int> alist;
    int i,j,k,x,y,z;
    alist.push(a);
    for(i=1;i<=b;i++)
    {
        vis[i]=0;
        dis[i]=0;
    }
    dis[a]=0;
    vis[a]=1;
    while(alist.size()>0)
    {
        z=alist.front();
        for(j=0;j<node[z].size();j++)
        {
            x=node[z][j];
            if(vis[x]==0)
            {
                alist.push(x);
                vis[x]=1;
                dis[x]=dis[z]+1;
            }
        }
        alist.pop();
    }
}
int main()
{
    int i,j,k,x,n,a,b,c,y,z,t,X=1;
    n=20;
    while(scanf("%d",&y)==1)
    {
        for(i=1;i<=y;i++)
        {
            scanf("%d",&a);
            node[1].push_back(a);
            node[a].push_back(1);
        }
    for(i=2;i<=n-1;i++)
    {
        scanf("%d",&x);
        for(j=1;j<=x;j++)
        {
            scanf("%d",&a);
            node[i].push_back(a);
            node[a].push_back(i);
        }
    }
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
    scanf("%d",&b);
    scanf("%d",&c);
    if(k==1)
        printf("Test Set #%d\n",X);
    bfs(b,n);
    if(b<=9)
        printf(" %d to ",b);
    else printf("%d to ",b);
    if(c<=9) printf(" %d: ",c);
    else printf("%d: ",c);
    printf("%d\n",dis[c]);
    }
    X++;
    for(i=1;i<=20;i++)
    {
        node[i].clear();
    }
    printf("\n");
    }
    return 0;
}
