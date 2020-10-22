#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1005][3];
ll arr[1005];
int n;
ll fun(int pos,int nisi)
{
    if(pos>n)
        return 0;
    if(dp[pos][nisi]!=-1)
            return dp[pos][nisi];
    ll res=0;
    if(pos==1)
    {
        res = max(res,arr[pos]+fun(pos+2,1));
        res =max(res,fun(pos+1,0));
    }
    else if(pos==n)
    {
        if(nisi==0)
        {
            res=max(res,arr[pos]+fun(pos+2,nisi));
        }
        else
        {
            res=max(res,fun(pos+1,nisi));
        }
    }
    else
    {
        res =max(res,fun(pos+1,nisi));
        res=max(res,arr[pos]+fun(pos+2,nisi));
    }
    return dp[pos][nisi]=res;
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
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof dp);
        ll req=fun(1,0);
        cout<<"Case "<<ks<<": "<<req<<endl;
    }

    return 0;
}
