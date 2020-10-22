#include<bits/stdc++.h>
using namespace std;
int vis[2000][2000];
int dis[2000][2000],cell[2000][2000];
int fx[]={-1,1,0,0};
int fy[]={0,0,1,-1};
int bfs(int xx,int yy,int r,int c)
{
    queue<int> q[2];
    int i,j,k,x,y,a,b;
    memset(vis,0,sizeof vis);
    vis[xx][yy]=1;
    dis[xx][yy]=0;
    q[0].push(xx);
    q[1].push(yy);
    while(q[0].size()>0 && q[1].size()>0)
    {
        x=q[0].front();
        y=q[1].front();
        for(k=0;k<4;k++)
        {
            a = x+fx[k];
            b = y+fy[k];
            if(a>=0 && a<r && b>=0 && b<c && cell[a][b]!=-1 && vis[a][b]==0)
            {
                vis[a][b]=1;
                dis[a][b]=dis[x][y]+1;
                q[0].push(a);
                q[1].push(b);
            }
        }
        q[0].pop();
        q[1].pop();
    }
}
int main()
{
    int r,c,i,j,k,n,x,y,xx,yy,XX,YY,z;
    while(scanf("%d %d",&r,&c)==2)
    {
        if(r==0 && c==0)
            break;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            scanf("%d",&y);
            for(j=0;j<y;j++)
            {
                scanf("%d",&z);
                cell[x][z]=-1;
            }
        }
        scanf("%d %d",&xx,&yy);
        scanf("%d %d",&XX,&YY);
        bfs(xx,yy,r,c);
        printf("%d\n",dis[XX][YY]);
        memset(cell,0,sizeof cell);
    }
    return 0;
}
