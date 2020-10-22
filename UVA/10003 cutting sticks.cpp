#include<bits/stdc++.h>
using namespace std;
long long cut;
int n;
long long dp[60][60],arr[60];
long long cutting(int b,int e)
{
    if(abs(e-b)<=1) return 0;
    if(dp[b][e]!=-1)
        return dp[b][e];
    long long ret= std::numeric_limits<long long>::max();
    //cout<<ret<<endl;
    for(int i=b+1;i<e;i++)
    {
        long long left=cutting(b,i);
        //cout<<left<<endl;
        long long right=cutting(i,e);
        long long cur = arr[e]-arr[b];
        //cout<<cur<<endl;
        long long sum =left+right+cur;
        //cout<<sum<<endl;
        ret=min(sum,ret);
    }
    return dp[b][e]=ret;
}
int main()
{
    int m,i,j;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        memset(dp,-1,sizeof dp);
        scanf("%d",&m);
        arr[0]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%lld",&arr[i]);
        }
        arr[m+1]=n;
        long long res=cutting(0,m+1);
        printf("The minimum cutting is %lld.\n",res);
    }
    return 0;
}
