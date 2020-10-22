#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[10005];
int n,k;
int dp[10005][101];
int fun(int pos,int sum)
{
    if(pos>=n)
    {
        if(sum==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[pos][sum]!=-1)
    {
        return dp[pos][sum];
    }
    int ans=0;
    if(pos==0)
    {
        int x=(sum+arr[pos])%k;
        if(x<0)
        {
            x+=k;
        }
        ans=max(ans,fun(pos+1,x));
    }
    else
    {
        int x=(sum+arr[pos])%k;
        if(x<0)
        {
            x+=k;
        }
        ans=max(ans,fun(pos+1,x));
        if(ans==1)
        {
            return dp[pos][sum]=ans;
        }
        x=(sum-arr[pos])%k;
        if(x<0)
        {
            x+=k;
        }
        ans=max(ans,fun(pos+1,x));

    }
    return dp[pos][sum]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>n>>k;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof dp);
        int req=fun(0,0);
        if(req)
            cout<<"Divisible\n";
        else
            cout<<"Not divisible\n";

    }
    return 0;
}
