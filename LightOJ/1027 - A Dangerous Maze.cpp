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
        int n;
        cin>>n;
        ll upor=0;
        ll niche=n;
        ll a1=0;
        ll a2=0;
        int cnt=0;
        int neg=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            if(x>0) cnt=1;
            if(x>0)
            {
                upor += x;
            }
            else
            {
                upor += abs(x);
                neg++;
            }
        }
        upor=upor*n;
        niche=niche*(n-neg);
        ll gc=__gcd(upor,niche);
        upor /= gc;
        niche=niche/gc;
        if(cnt==1)
        {
            cout<<"Case "<<ks<<": "<<upor<<"/"<<niche<<endl;
        }
        else cout<<"Case "<<ks<<": "<<"inf"<<endl;
        ks++;
    }
    return 0;
}
