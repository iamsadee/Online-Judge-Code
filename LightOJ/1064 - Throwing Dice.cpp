#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef unsigned long long ll;
int n,lagbe;
ll dp[26][151];
ll fun(int pos,int sum)
{
    if(pos>=n)
    {
        if(sum>=lagbe) return 1;
        return 0;
    }
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    ll res=0;
    for(int i=1;i<=6;i++)
    {
        res+=fun(pos+1,sum+i);
    }
    return dp[pos][sum]=res;
}
ll pre[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    pre[0]=1LL;
    for(int i=1;i<=25;i++)
    {
        pre[i]=pre[i-1]*6LL;
    }
    for(int ks=1;ks<=t;ks++)
    {
        cin>>n>>lagbe;
        memset(dp,-1,sizeof dp);
        ll p=fun(0,0);
        ll q=pre[n];
        ll gc=__gcd(p,q);
        p=p/gc;
        q=q/gc;
        if(q!=1) cout<<"Case "<<ks<<": "<<p<<"/"<<q<<endl;
        else cout<<"Case "<<ks<<": "<<p<<endl;
    }
    return 0;
}
