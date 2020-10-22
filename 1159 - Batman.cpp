#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[51][51][51];
string a,b,c;
int n,m,o;
int fun(int i,int j,int k)
{
    if(i>=n || j>=m || k>=o)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    int res=0;
    if(a[i]==b[j] && b[j]==c[k])
    {
        res=max(res,1+fun(i+1,j+1,k+1));
    }
    res=max(res,fun(i+1,j,k));
    res=max(res,fun(i,j+1,k));
    res=max(res,fun(i,j,k+1));
    res=max(res,fun(i+1,j+1,k));
    res=max(res,fun(i+1,j,k+1));
    res=max(res,fun(i,j+1,k+1));
    return dp[i][j][k]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>a>>b>>c;
        n=a.size();
        m=b.size();
        o=c.size();
        memset(dp,-1,sizeof dp);
        int res=fun(0,0,0);
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
