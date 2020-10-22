#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string a,b;
void bin(ll x)
{
    a.clear();
    b.clear();
    while(x!=0)
    {
        ll y=x%2;
        x=x/2;
        b.push_back(y+'0');
    }
    n=b.size();
    reverse(b.begin(),b.end());
    //cout<<b<<endl;
    for(int i=0; i<n; i++)
    {
        a.push_back('0');
    }
}
ll dp[33][2][2][35];
ll fun(int pos,int boro,int prev,int cnt)
{
    if(pos==n)
        return cnt;
    if(dp[pos][boro][prev][cnt]!=-1)
        return dp[pos][boro][prev][cnt];
    int lw=0;
    int hi=1;
    if(boro==0)
    {
        hi=b[pos]-'0';
    }
    ll ret=0;
    for(int i=lw; i<=hi; i++)
    {
        if(pos>0)
        {
            if(prev==1 && i==1)
            {
                ret += fun(pos+1,boro|(i<hi),i,cnt+1);
            }
            else
            {
                ret += fun(pos+1,boro|(i<hi),i,cnt);
            }
        }
        else
        {
            ret += fun(pos+1,boro|(i<hi),i,cnt);
        }
    }
    return dp[pos][boro][prev][cnt]=ret;
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
        ll x;
        cin>>x;
        //cout<<x<<endl;
        bin(x);
        memset(dp,-1,sizeof dp);
        ll res=fun(0,0,0,0);
        cout<<"Case "<<k<<": "<<res<<endl;
        k++;
    }
    return 0;
}
