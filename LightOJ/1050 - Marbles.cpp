#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r,b;
int vis[505][505][2];
double dp[505][505][2];
double fun(int x,int y,bool turn)
{
    if(x==0 && (y==1))
    {
        return 1.0;
    }
    if(y==0 && turn==1)
    {
        return 0.0;
    }
    if(vis[x][y][turn]) return dp[x][y][turn];
    double res=0;
    if(turn==1)
    {
        if(y>0)
        {
            res=fun(x,y-1,0);
        }
    }
    else
    {
        if(y>0)
        {
            res += ((y*1.0)/((x+y)*1.0))*fun(x,y-1,1);
        }
        if(x>0)
        {
            res += ((x*1.0)/((x+y)*1.0))*fun(x-1,y,1);
        }
    }
    vis[x][y][turn]=1;
    return dp[x][y][turn]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    cin>>t;
    int ks=1;
    memset(vis,0,sizeof vis);
    while(t--)
    {
        cin>>r>>b;
        double ans=fun(r,b,0);
        printf("Case %d: %0.6lf\n",ks++,ans);
    }
    return 0;
}
