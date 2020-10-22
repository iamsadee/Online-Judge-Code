#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n,m,d;
ll dp[202][11][56];
long long arr[202];
ll fun(int i,int taken,int sum)
{
    if(i>=n)
    {
        if(taken==m && sum%d==0)
        {
            return 1;
        }
        else return 0;
    }
    if(taken>m)
        return 0;
    else if(taken==m && sum%d==0)
        return 1;
    else if(taken==m && sum%d!=0)
        return 0;
    if(dp[i][taken][sum]!=-1)
        return dp[i][taken][sum];
    ll res1=0,res2=0;
    res1=fun(i+1,taken+1,sum+(arr[i]%d+d)%d);
    res2=fun(i+1,taken,sum);
    return dp[i][taken][sum]=res1+res2;
}
int main()
{
    int q,i,j=1,k;
    while(scanf("%d %d",&n,&q)==2)
    {
        if(n==0 && q==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        printf("SET %d:\n",j++);
        for(i=1;i<=q;i++)
        {
            memset(dp,-1,sizeof dp);
            //clr();
            scanf("%d %d",&d,&m);
            ll x = fun(0,0,0);
            printf("QUERY %d: %llu\n",i,x);
        }
    }
    return 0;
}
