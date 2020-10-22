#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m;
int dp[102][102];
string ch;
ll fun(int l,int r)
{
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    ll res=105;
    if(ch[l]==ch[r])
    {
        res=min(res,fun(l+1,r-1));
    }
    res=min(res,1+fun(l+1,r));
    res=min(res,1+fun(l,r-1));
    return dp[l][r]=res;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    int t;
    //scanf("%d",&t);
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
         memset(dp,-1,sizeof dp);
        cin>>ch;
        n=ch.size();
        ll res=fun(0,n-1);
        printf("Case %d: %lld\n",ks,res);
    }
    return 0;
}
