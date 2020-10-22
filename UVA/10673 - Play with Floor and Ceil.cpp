#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        ll x,k;
        cin>>x>>k;
        cout<<k-(x%k)<<' '<<(x%k)<<'\n';
    }
    return 0;
}
