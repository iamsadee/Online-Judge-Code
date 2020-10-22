#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
ll dp[61][61];
int n;
ll fun(int l,int r)
{
    if(l>r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    ll res=0;
    if(a[l]==a[r])
    {
        res=1+fun(l+1,r-1)+fun(l+1,r)+fun(l,r-1)-fun(l+1,r-1);
    }
    else
    {
        res = fun(l+1,r)+fun(l,r-1)-fun(l+1,r-1);
    }
    return dp[l][r]=res;
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
        cin>>a;
        n=a.size();
        memset(dp,-1,sizeof dp);
        ll res=fun(0,n-1);
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
