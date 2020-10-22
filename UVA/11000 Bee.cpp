#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100005];
ll fib(ll n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fib(n-1)+fib(n-2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while(cin>>n)
    {
        if(n==-1)
            break;
        memset(dp,-1,sizeof dp);
        cout<<fib(n)-1<<' '<<fib(n+1)-1<<'\n';
    }

    return 0;
}
