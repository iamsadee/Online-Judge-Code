/// Idea Hashing
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ch;
ll pre[1000002];
ll mod=1000000007;
ll b=347;
ll inverse;
ll bigmod(ll a,ll p,ll m)
{
    if(p==0)
        return 1%m;
    if(p%2!=0)
    {
        return (a*(bigmod(a,p-1,m)))%m;
    }
    else
    {
        ll x=(bigmod(a,p/2,m))%m;
        return (x*x)%m;
    }
}
ll hashing()
{
    ll r=ch.size()-1;
    ll l=0;
    int n=ch.size();
    ll h1=0,h2=0;
    for(int i=0; i<n; i++)
    {
        h1 =(h1+((ch[i]%mod*pre[r]%mod)%mod))%mod;
        h2 =(h2+((ch[i]%mod*pre[l]%mod)%mod))%mod;

        l++;
        r--;
    }
    if(h1==h2)
    {
        return 0;
    }
    else
    {
        l=0;
        r=n-1;
        for(int i=0; i<n; i++)
        {
            h1 =(h1-((ch[i]%mod*pre[r]%mod)%mod))%mod;
            h2 =(h2%mod-ch[i]%mod)%mod;
            if(h2<0) h2 +=mod;

            h2= (h2*inverse)%mod;
            if(h2<0) h2 +=mod;
            //h2 = (h2%mod*inverse%mod)%mod;
            if(h1<0) h1 +=mod;
            //cout<<h1<<" "<<h2<<endl;
            if(h1==h2)
            {
                return i+1;
            }
            r--;
            l++;

        }
    }
    return n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inverse=bigmod(b,(mod-2),mod);
    pre[0]=1;
    for(int i=1; i<=1e6; i++)
    {
        pre[i]=(pre[i-1]*b)%mod;
    }

    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>ch;
        ll x=hashing();
        cout<<"Case "<<ks<<": "<<x+ch.size()<<"\n";
    }
    return 0;
}
