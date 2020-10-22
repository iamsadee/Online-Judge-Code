#include<bits/stdc++.h>
using namespace std;
string ch[25];
int n,m;
bool vis[25][25];
int valid(int row,int col)
{
    if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && ch[row][col]=='.')
    {
        return 1;
    }
    else return 0;
}
int x[]={1,0,0,-1};
int y[]={0,-1,1,0};
int cnt;
void dfs(int row,int col)
{
    vis[row][col]=1;
    for(int i=0;i<4;i++)
    {
        if(valid(row+x[i],col+y[i]))
        {
            cnt++;
            dfs(row+x[i],col+y[i]);
        }
    }
}
void clr()
{
    for(int i=0;i<n;i++)
    {
        memset(vis[i],0,sizeof vis[i]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&m,&n);
        getchar();
        int j;
        clr();
        for(j=0;j<n;j++)
        {
            cin>>ch[j];
        }
        int a,b;
        for(j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(ch[j][k]=='@')
                {
                    a=j;
                    b=k;
                }
            }
        }
        cnt=1;
        //cout<<a<<' '<<b<<endl;
        //cout<<"DFS"<<endl;
        dfs(a,b);
        cout<<"Case "<<i<<": "<<cnt<<'\n';
    }
    return 0;
}
