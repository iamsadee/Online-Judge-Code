#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,w;
int p[105],c[105],wt[105];
int dp[102][10002];
int fun(int pos,int sum)
{
    if(sum>w)
    {
            return -1e9;
    }
    if(pos>=n)
    {
            if(sum<=w) return 0;
            else return -1e9;
    }
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    ll res1=p[pos]+fun(pos,sum+wt[pos]);
    ll res2=fun(pos+1,sum);
    return dp[pos][sum]=max(res1,res2);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d %d",&n,&w);
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&p[i],&c[i],&wt[i]);
            sum += c[i]*wt[i];
        }
        if(sum>w)
        {
            printf("Case %d: Impossible\n",ks);
        }
        else
        {
            w -= sum;
            int res=fun(0,0);
            printf("Case %d: %d\n",ks,res);
        }
    }

    return 0;
}
