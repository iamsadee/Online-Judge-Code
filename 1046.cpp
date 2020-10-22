///LOJ 1046 Rider
///Simple BFS
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
int n,m;
string ch[10];
int pre[10][10];
bool vis[10][10];
bool valid(int a,int b)
{
    if(a<0 || a>=n || b<0 || b>=m)
    {
        return 0;
    }
    return true;
}
int x[]={1,1,2,2,-1,-1,-2,-2};
int y[]={2,-2,1,-1,2,-2,1,-1};
void bfs(int r,int c)
{
    queue<int>q1,q2;
    q1.push(r);
    q2.push(c);
    vis[r][c]=1;
    while(q1.size()>0)
    {
        int x1=q1.front();
        q1.pop();
        int y1=q2.front();
        q2.pop();
        for(int i=0;i<8;i++)
        {
            int nx=x1+x[i];
            int ny=y1+y[i];
            if(valid(nx,ny) && vis[nx][ny]==0)
            {
                vis[nx][ny]=1;
                pre[nx][ny]=pre[x1][y1]+1;
                q1.push(nx);
                q2.push(ny);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int ks=1;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>ch[i];
        }
        ll res=1e18;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                memset(pre,0,sizeof pre);
                memset(vis,0,sizeof vis);
                ll nw=0;
                bfs(i,j);
                //cout<<i<<" "<<j<<endl;
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        if(ch[k][l]>='1' && ch[k][l]<='9')
                        {
                            int d=ch[k][l]-'0';
                            if(vis[k][l]==1 )
                            {
                                nw += (pre[k][l]/d);
                                if(pre[k][l]%d) nw++;

                                //cout<<pre[k][l]<<" "<<k<<" "<<l<<endl;
                            }
                            else
                            {
                                nw=-1;
                                break;
                            }
                        }
                    }
                    if(nw==-1)
                    {
                        break;
                    }
                }
                //cout<<endl;
                if(nw!=-1)
                {
                    //cout<<nw<<endl<<endl;
                    res=min(res,nw);
                }

            }
        }
        cout<<"Case "<<ks<<": ";
        ks++;
        if(res==1e18)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<res<<"\n";
        }
    }
    return 0;
}
