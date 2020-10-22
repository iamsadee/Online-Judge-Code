#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll dp[45][2];
ll fun(int pos,int prev)
{
    if(pos==43)
        return 1LL;
    if(dp[pos][prev]!=-1)
        return dp[pos][prev];
    ll ret=0;
    ret += fun(pos+1,0);
    if(prev!=1)
    {
        ret += fun(pos+1,1);
    }
    return dp[pos][prev]=ret;
}
string ans;
void path(int pos,int prev,ll n)
{
    if(pos==43) return ;
    ll cnt=fun(pos+1,0);
    if(n<=cnt)
    {
        ans += '0';
        path(pos+1,0,n);
    }
    else
    {
        ans +='1';
        path(pos+1,prev,n-cnt);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    memset(dp,-1,sizeof dp);
    ll an=fun(0,0);
    cin>>t;
    int k=0;
    while(t--)
    {
        ans.clear();
        ll n;
        cin>>n;
        n++; /// as zero added .
        path(0,0,n);
        int i=0;
        while(i<ans.size() && ans[i]=='0')
        {
            i++;
        }
        k++;
        cout<<"Case "<<k<<": ";
        while(i<ans.size())
        {
            cout<<ans[i];
            i++;
        }
        cout<<endl;
    }
    return 0;
}
