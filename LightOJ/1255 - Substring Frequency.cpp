/// Hashing
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ch,pat;
ll pre[1000002];
ll mod=1000000007;
ll b=347;
ll hashing()
{
    ll r=ch.size()-1;
    ll l=0;
    int n=ch.size();
    ll h1=0,h2=0;
    if(pat.size()>ch.size())
        return 0;
    r=pat.size()-1;
    int m=pat.size();
    for(int i=0;i<m;i++)
    {
        h1 += (pat[i]%mod*pre[r]%mod)%mod;
        if(h1>=mod)
            h1=h1%mod;
        r--;
    }
    ll cnt=0;
    r=m-1;
    for(int i=0;i<m;i++)
    {
        h2 +=(ch[i]%mod * pre[r]%mod)%mod;
        if(h2>=mod)
        {
            h2=h2%mod;
        }
        r--;
    }
    if(h1==h2)
    {
        cnt++;
    }
    r=m-1;
    int j=0;
    for(int i=m;i<n;i++)
    {
        h2 -= (ch[j]%mod * pre[r]%mod)%mod;
        if(h2<0) h2 +=mod;
        h2 = h2*b;
        if(h2>=mod) h2=h2%mod;
        h2 += ch[i];
        if(h2>=mod)
            h2=h2%mod;
        j++;
        if(h1==h2) cnt++;
    }
    return cnt;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //inverse=bigmod(b,(mod-2),mod);
    pre[0]=1;
    for(int i=1; i<=1e6; i++)
    {
        pre[i]=(pre[i-1]*b)%mod;
    }
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>ch>>pat;
        ll x=hashing();
        cout<<"Case "<<ks<<": "<<x<<"\n";
    }
    return 0;
}
