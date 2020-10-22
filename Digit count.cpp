#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll arr[11];
ll dp[12][12];
ll fun(int pos,ll prev)
{
    if(pos==n)
        return 1LL;
    if(dp[pos][prev]!=-1)
        return dp[pos][prev];
        ll ret=0;
    for(int i=0;i<m;i++)
    {
        if(pos>0)
        {
            ll dif=abs(arr[i]-prev);
            if(dif<=2)
            {
                ret+=fun(pos+1,arr[i]);
            }
        }
        else
        {
            ret += fun(pos+1,arr[i]);
        }
    }
    return dp[pos][prev]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int k=1;
    while(t--)
    {
        cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof dp);
        ll ans=fun(0,0);
        cout<<"Case "<<k<<": "<<ans<<endl;
        k++;
    }
    return 0;
}
