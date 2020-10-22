#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[505][505];
ll a1[505][505];
ll a2[505][505];
ll fun(int i,int j)
{
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll res=max(a2[i][j]+fun(i-1,j),a1[i][j]+fun(i,j-1));
    return dp[i][j]=res;
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
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a2[i][j];
                if(j>0)
                {
                    a2[i][j]+=a2[i][j-1];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a1[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>0)
                {
                    a1[j][i] +=a1[j-1][i];
                }
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<ks<<": "<<fun(n-1,m-1)<<"\n";
    }
    return 0;
}
