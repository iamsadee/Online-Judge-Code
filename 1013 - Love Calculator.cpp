#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m;
ll dp[35][35],dp1[35][35][75];
string a,b;
ll fun(int l,int r)
{
    if(l==a.size() || r==b.size()) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    ll res=0;
    if(a[l]==b[r])
    {
        res=max(res,1+fun(l+1,r+1));
    }
    res=max(res,fun(l+1,r));
    res=max(res,fun(l,r+1));
    return dp[l][r]=res;

}
int len;
ll path(int i,int j,int l)
{
    if(i==a.size())
    {
        int req=b.size()-j;
        req +=l;
        //cout<<req<<" "<<len<<endl;
        if(req==len) return 1LL;
        else return 0;
    }
    if(j==b.size())
    {
        int req=a.size()-i;
        req +=l;
        if(req==len) return 1LL;
        else return 0;
    }
    if(dp1[i][j][l]!=-1)
        return dp1[i][j][l];
    ll res=0;
    if(a[i]==b[j])
    {
        res +=path(i+1,j+1,l+1);
    }
    else
    {
        res += path(i+1,j,l+1);
        res += path(i,j+1,l+1);
    }

    return dp1[i][j][l]=res;
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
        cin>>a>>b;
        //cout<<fun(0,0)<<endl;
        len=(a.size()+b.size())-fun(0,0);
        memset(dp1,-1,sizeof dp1);
        ll res=path(0,0,0);

        printf("Case %d: %d %lld\n",ks,len,res);
    }
    return 0;
}
