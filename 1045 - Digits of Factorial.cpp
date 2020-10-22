#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static double arr[1000005];
//arr[0]=0.0;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    for(int m=1;m<=1000002;m++)
    {
        arr[m] = arr[m-1] + log10(m);
    }
    int t;
    scanf("%d",&t);
    int i,j,k;
    for(i=1;i<=t;i++)
    {
        ll n,b;
        scanf("%lld %lld",&n,&b);
        //cin>>n>>b;
        double res = arr[n]/((log10(b))*1.0);
        ll ans = floor(res) +1;
        cout<<"Case "<<i<<": "<<ans<<'\n';

    }
    return 0;
}
