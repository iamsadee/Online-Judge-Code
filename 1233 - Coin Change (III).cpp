#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll coin[105];
ll ase[105];
bool dp[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int ks=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            cin>>coin[i];
        }
        for(int i=1; i<=n; i++)
        {
            cin>>ase[i];
        }
        int cnt[m+2];
        for(int i=1;i<=m;i++)
        {
            dp[i]=0;
            cnt[i]=0;
        }
        cnt[0]=0;
        dp[0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=coin[i]; j<=m; j++)
            {
                if(dp[j-coin[i]]==1 && dp[j]==0)
                {
                    ///cnt[j-coin[i]] used to check if i am using coin[i] then if limit of using coin[i] exceed or not
                    if((cnt[j-coin[i]]+1) <=ase[i])
                    {
                        cnt[j] +=cnt[j-coin[i]];
                        cnt[j]++;
                        dp[j]=1;
                    }
                    else
                    {
                        cnt[j]=0;
                    }
                }
            }
            for(int j=1;j<=m;j++)
            {
                cnt[j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            if(dp[i]) ans++;
        }
        cout<<"Case "<<ks++<<": "<<ans<<"\n";
    }
    return 0;
}
