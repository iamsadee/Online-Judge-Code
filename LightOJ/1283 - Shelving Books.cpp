#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[103][103][103];
ll arr[105];
ll fun(int pos,int left,int right)
{
    if(pos>n)
        return 0;
    if(dp[pos][left][right]!=-1)
        return dp[pos][left][right];
    ll res=0;
    if(arr[pos]>=arr[left] && arr[right]>=arr[pos])
    {
        res=max(res,1+fun(pos+1,pos,right));
        res=max(res,1+fun(pos+1,left,pos));
    }
    res=max(res,fun(pos+1,left,right));
    return dp[pos][left][right]=res;
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
        memset(dp,-1,sizeof dp);
        cin>>n;
        arr[0]=-1e6;
        arr[n+1]=1e6;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        ll res=fun(1,0,n+1);
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
