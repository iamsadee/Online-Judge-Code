#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        ll dp[m];
        for(int i=0;i<m;i++)
        {
            dp[i]=0;
        }
        dp[0]=1;
        ll sum=0;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            sum +=x;
            sum=sum%m;
            ans += dp[sum];
            dp[sum]++;
        }
        cout<<"Case "<<ks++<<": "<<ans<<"\n";
    }
    return 0;
}
