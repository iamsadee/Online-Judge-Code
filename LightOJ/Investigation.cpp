#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
int n,k;
ll dp[11][2][2][85][85];
ll fun(int pos,int boro,int choto,int sum,ll num)
{
    if(pos==n)
    {
        if(sum%k==0 & num%k==0)
            return 1;
        else return 0;
    }
    if(dp[pos][boro][choto][sum][num]!=-1)
        return dp[pos][boro][choto][sum][num];
    int lw=0;
    int hi=9;
    if(boro==0) lw=a[pos]-'0';
    if(choto==0) hi=b[pos]-'0';
    ll ret=0;
    for(int i=lw;i<=hi;i++)
    {
        ret += fun(pos+1,boro|(i>lw),choto|(i<hi),sum+i,((num*10LL)+(ll)i)%k);
    }
    return dp[pos][boro][choto][sum][num]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int p=0;
    while(t--)
    {
        cin>>a>>b>>k;
        n=b.size();
        string tmp;
        int x=n-a.size();
        for(int i=0; i<x; i++)
        {
            tmp.push_back('0');
        }
        tmp +=a;
        a=tmp;
        //cout<<a<<" "<<b<<endl;
        memset(dp,-1,sizeof dp);
        ll ans=fun(0,0,0,0,0);
        p++;
        cout<<"Case "<<p<<": "<<ans<<endl;
    }
    return 0;
}
