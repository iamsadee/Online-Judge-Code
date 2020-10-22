#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int n,k;
ll dp[65538][21];
int m;
int mark[200];
ll bigmod(ll a,ll p,ll m)
{
    if(p==0)
        return 1%m;
    if(p%2!=0)
    {
        return (a*(bigmod(a,p-1,m)))%m;
    }
    else
    {
        ll x=(bigmod(a,p/2,m))%m;
        return (x*x)%m;
    }
}
ll fun(int mask,int sum)
{
    if(mask==((1<<(m))-1))
    {
        if(sum==0)
            return 1LL;
        return 0;
    }
    if(dp[mask][sum]!=-1)
        return dp[mask][sum];
    ll res=0;
    for(int i=0;i<m;i++)
    {
        int req=mask&(1<<i);
        if(req==0)
        {
            ll ase=__builtin_popcountll(mask);
            ll po=(m-ase)-1LL;
            ll koto=mark[a[i]]*bigmod(n,po,k);
            res += fun(mask|(1<<i),(sum+koto)%k);
        }
    }
    return dp[mask][sum]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mark['0']=0;
    mark['1']=1;
    mark['2']=2;
    mark['3']=3;
    mark['4']=4;
    mark['5']=5;
    mark['6']=6;
    mark['7']=7;
    mark['8']=8;
    mark['9']=9;
    mark['A']=10;
    mark['B']=11;
    mark['C']=12;
    mark['D']=13;
    mark['E']=14;
    mark['F']=15;
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>n>>k;
        cin>>a;
        memset(dp,-1,sizeof dp);
        m=a.size();
        string tmp;
        for(int i=0;i<m;i++)
        {
            if(mark[a[i]]<=(n-1))
            {
                tmp.push_back(a[i]);
            }
        }
        a=tmp;
        m=a.size();
        ll res=fun(0,0);
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
