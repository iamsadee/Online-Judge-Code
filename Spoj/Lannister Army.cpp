///DP - Divide and Conquer Optimization
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int arr[5005];
int pre[5005][5005];
int dp[5005][5005];
void fun(int kk,int l,int r,int oL,int oR)
{
    if(l>r)
        return;
    int mid=(l+r)/2;
    int sz=min(oR,mid);
    dp[kk][mid]=1e7;
    int id=oL;
    for(int i=oL;i<=sz;i++)
    {
        int req=dp[kk-1][i-1]+pre[i][mid];
        if((req<dp[kk][mid]))
        {
            id=i;
            dp[kk][mid]=req;
        }
    }
    fun(kk,l,mid-1,oL,id);
    fun(kk,mid+1,r,id,oR);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(arr[i]>arr[j])
            {
                pre[i][j]=1;
            }
            pre[i][j] += pre[i][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n-1;j>=1;j--)
        {
            pre[j][i] +=pre[j+1][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=pre[1][i];
        //cout<<pre[1][i]<<" ";
    }
    for(int i=2;i<=k;i++)
    {
        fun(i,i,n,i,n);
    }
    cout<<dp[k][n]<<"\n";
    return 0;
}
