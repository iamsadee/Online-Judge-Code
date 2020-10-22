#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> st;
string a;
int d,m;
ll dp[1026][1003];
ll fun(int mask,int sum)
{
    if(mask==((1<<(m))-1))
    {
        if(sum==0)
            return 1LL;
        return 0;
    }
    if(dp[mask][sum]!=-1)
        return dp[mask][sum];
    ll res=0;
    for(int i=0;i<m;i++)
    {
        int req=mask&(1<<i);
        if(req==0)
        {
            res += fun(mask|(1<<i),((sum*10LL)+(a[i]-'0'))%d);
        }
    }
    return dp[mask][sum]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll pre[15];
    pre[0]=1;
    for(ll i=1;i<=10;i++)
    {
        pre[i]=pre[i-1]*i;
    }
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        st.clear();
        cin>>a>>d;
        memset(dp,-1,sizeof dp);
        m=a.size();
        map<int ,int> mp;
        for(int i=0;i<m;i++)
        {
            mp[a[i]-'0']++;
        }
        //set<int>::iterator it;
        ll res=fun(0,0);
        for(int i=0;i<=9;i++)
        {
            res = res/(pre[mp[i]]);
        }
        cout<<"Case "<<ks<<": "<<res<<"\n";
    }
    return 0;
}
