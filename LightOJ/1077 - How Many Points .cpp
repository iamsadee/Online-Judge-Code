#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//static double arr[1000005];
//arr[0]=0.0;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    scanf("%d",&t);
    int i,j,k;
    for(i=1;i<=t;i++)
    {
        ll x,y,a,b;
        scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
        //cin>>n>>b;
        ll ans=__gcd(abs(x-a),abs(y-b))+1; ///number of latis point
        cout<<"Case "<<i<<": "<<ans<<'\n';

    }
    return 0;
}
