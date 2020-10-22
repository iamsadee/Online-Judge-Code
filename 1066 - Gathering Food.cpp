#include<bits/stdc++.h>
using namespace std;
int vis[20][20];
int dis[20][20];
string ch[100];
int fx[]= {-1,1,0,0};
int fy[]= {0,0,1,-1};
void bfs(int xx,int yy,int r,int c,char pp)
{
    queue<int> q[2];
    int i,j,k,x,y,a,b;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    vis[xx][yy]=1;
    dis[xx][yy]=0;
    q[0].push(xx);
    q[1].push(yy);
    while(q[0].size()>0 && q[1].size()>0)
    {
        x=q[0].front();
        y=q[1].front();
        for(k=0; k<4; k++)
        {
            a = x+fx[k];
            b = y+fy[k];
            if(a>=0 && a<r && b>=0 && b<c && (ch[a][b]=='.' || (ch[a][b]>='A' && ch[a][b]<=pp))  && vis[a][b]==0)
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
struct A
{
    char c;
    int x,y;
};
A arr[30];
bool cmp(A x,A y)
{
    return x.c<y.c;
}
int main()
{
    int r,c,i,j,k,n,x,y,xx,yy,XX,YY,z;
    int t;
    scanf("%d",&t);
    for(int a=1; a<=t; a++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>ch[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ch[i][j]>='A' && ch[i][j]<='Z')
                {
                    arr[cnt].c=ch[i][j];
                    arr[cnt].x=i;
                    arr[cnt].y=j;
                    cnt++;
                }
            }
        }
        sort(arr,arr+cnt,cmp);
        long long ans=0;
        bool chk=0;
        for(int i=1;i<cnt;i++)
        {
            int x=arr[i].x;
            int y=arr[i].y;
            bfs(arr[i-1].x,arr[i-1].y,n,n,arr[i].c);
            if(dis[x][y]!=0)
            {
                ans += dis[x][y];
            }
            else
            {
                chk=1;
            }
        }
        if(chk)
        {
            printf("Case %d: Impossible\n",a);
        }
        else
        {
            printf("Case %d: %lld\n",a,ans);
        }
    }
    return 0;
}

