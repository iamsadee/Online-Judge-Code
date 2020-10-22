///Bitmask DP
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[9][260][260];
ll grid[8];
int n,m;
int toggle(int x,int pos)
{
    return x^(1<<pos);
}
ll fun(int pos,int prev,int cur)
{
    if(pos==n)
    {
        if(prev==(1<<m)-1)
        {
            return 0;
        }
        else return 1e15;
    }
    if(dp[pos][prev][cur]!=-1)
        return dp[pos][prev][cur];
    int sz=(1<<m);
    ll res=1e15;
    int mask[3];
    for(int i=0;i<sz;i++)
    {
        mask[0]=prev;
        mask[1]=cur;
        mask[2]=grid[pos+1];
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                mask[0]=toggle(mask[0],j);
                mask[1]=toggle(mask[1],j);
                mask[2]=toggle(mask[2],j);
                if(m>1)
                {
                    if(j==0)
                    {
                        mask[0]=toggle(mask[0],j+1);
                        mask[1]=toggle(mask[1],j+1);
                        mask[2]=toggle(mask[2],j+1);
                    }
                    else if(j==m-1)
                    {
                        mask[0]=toggle(mask[0],j-1);
                        mask[1]=toggle(mask[1],j-1);
                        mask[2]=toggle(mask[2],j-1);
                    }
                    else
                    {
                        mask[0]=toggle(mask[0],j+1);
                        mask[1]=toggle(mask[1],j+1);
                        mask[2]=toggle(mask[2],j+1);
                        mask[0]=toggle(mask[0],j-1);
                        mask[1]=toggle(mask[1],j-1);
                        mask[2]=toggle(mask[2],j-1);
                    }
                }
            }
        }
        if(pos==0)
        {
            res=min(res,cnt+fun(pos+1,mask[1],mask[2]));
        }
        else if(mask[0]==(1<<m)-1)
        {
            res=min(res,cnt+fun(pos+1,mask[1],mask[2]));
        }
    }
    return dp[pos][prev][cur]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1;ks<=t;ks++)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            grid[i]=0;
            string ch;
            cin>>ch;
            for(int j=0;j<m;j++)
            {
                if(ch[j]=='*')
                {
                    grid[i] |=(1<<j);
                }
            }
        }
        memset(dp,-1,sizeof dp);
        ll res=fun(0,0,grid[0]);
        if(res==1e15)  cout<<"Case "<<ks<<": "<<"impossible"<<"\n";
        else cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
