///Patern Katalan Number
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=100000007LL;
ll fac[302231];
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
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    vector<ll> arr;
    set<ll> st;
    for(ll i=2LL; i<=1e5; i++)
    {
        ll req=i*i;
        while(req<=1e10)
        {
            st.insert(req);
            req=req*i;
        }
    }
    set<ll>::iterator it;
    for(it=st.begin(); it!=st.end(); it++)
    {
        arr.push_back((*it));
    }
    int x=300000LL;
    fac[0]=1;
    for(int i=1; i<=x; i++)
    {
        fac[i]=fac[i-1]*(ll)i;
        if(fac[i]>=mod)
            fac[i] %=mod;
    }
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        int id=upper_bound(arr.begin(),arr.end(),b)-lower_bound(arr.begin(),arr.end(),a);
        if(id==0)
        {
            printf("Case %d: 0\n",ks);
        }
        else
        {
            ll upor=fac[2*id];
            ll niche=fac[id+1]*fac[id];
            if(niche>=mod)
                niche %=mod;
            upor=upor*bigmod(niche,mod-2,mod);
            if(upor>=mod)
                upor %=mod;
            printf("Case %d: %lld\n",ks,upor);
        }
    }
    return 0;
}
