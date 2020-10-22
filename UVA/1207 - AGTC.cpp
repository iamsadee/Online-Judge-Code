#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
int dp[2005][2005];
int fun(int i,int j)
{
    if(i==a.size())
    {
        return b.size()-j;
    }
    if(j==b.size())
    {
        return a.size()-i;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int res=0,res1,res2,res3;
    if(a[i]==b[j] )
    {
        res = fun(i+1,j+1);
    }
    else
    {
        res1=1+fun(i+1,j);
        res2=1+fun(i,j+1);
        res3=1+fun(i+1,j+1);
        res=min(res1,res2);
        res=min(res,res3);
    }
    return dp[i][j]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    while(cin>>x)
    {
        memset(dp,-1,sizeof dp);
        cin>>a;
        cin>>y;
        cin>>b;
        int ans=fun(0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
