#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int ks=1;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=1;
        ll mod=1000000007;
        if(n%3==0)
        {
            ans=ans*(n/3);
            ans=ans%mod;
        }
        else
        {
            ans=ans*(n);
            ans=ans%mod;
        }
        if((n+1)%3==0)
        {
            ans=ans*(n+1)/3;
            ans=ans%mod;
        }
        else
        {
            ans=ans*(n+1);
            ans=ans%mod;
        }
        if((n+2)%3==0)
        {
            ans=ans*(n+2)/3;
            ans=ans%mod;
        }
        else
        {
            ans=ans*(n+2);
            ans=ans%mod;
        }
        cout<<"Case "<<ks<<": "<<ans<<endl;
        ks++;


    }
    return 0;
}
