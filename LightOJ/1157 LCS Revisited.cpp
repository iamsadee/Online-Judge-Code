#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
///Number LCS distinct in two string .
int dp[1005][1005];
string a,b;
int res[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1;ks<=t;ks++)
    {
        cin>>a>>b;
        int n1=a.size();
        int n2=b.size();
        ll mod=1000007LL;
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                    res[i][j]=1;
                }
                else
                {
                    if(a[i-1]==b[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                        res[i][j]=res[i-1][j-1];
                    }
                    else
                    {
                        res[i][j]=0;
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                        if(dp[i][j]==dp[i-1][j])
                        {
                            res[i][j]+=res[i-1][j];
                            if(res[i][j]>=mod)
                            {
                                res[i][j] %=mod;
                            }
                        }
                        if(dp[i][j]==dp[i][j-1])
                        {
                            res[i][j]+=res[i][j-1];
                            if(res[i][j]>=mod)
                            {
                                res[i][j] %=mod;
                            }
                        }
                        if(dp[i][j]==dp[i-1][j-1])
                        {
                            res[i][j] -= res[i-1][j-1];
                            if(res[i][j]>=mod)
                            {
                                res[i][j] %=mod;
                            }
                            if(res[i][j]<0)
                            {
                                res[i][j] +=mod;
                            }
                        }
                    }
                }
            }
        }
        cout<<"Case "<<ks<<": "<<res[n1][n2]<<"\n";
    }
    return 0;
}
