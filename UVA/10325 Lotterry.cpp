#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/// Inclusion-Exclusion using bitmask
int cnt=0;
ll arr[20];
ll chk(ll x)
{
    ll i=1;
    ll ans=1;
    cnt=0;
    while(x>0)
    {
        int y=x%2;
        x=x/2;
        if(y==1)
        {
            cnt++;
            ll z=__gcd(ans,arr[i]);
            //cout<<arr[i]<<' ';
            ans = ((ans)*(arr[i]/z));
            //cout<<"GCD : "<<z<<endl<<endl;
        }
        i++;
    }
    //cout<<endl<<ans<<" ans :"<<endl;
    return ans;
}
int main()
{
    ll num,k;
    while(scanf("%lld %lld",&num,&k)==2)
    {

        int i,j;
        for(int i=1;i<=k;i++)
        {
            scanf("%lld",&arr[i]);
        }
        ll mask;
        ll ans=0;
        for(mask=1;mask<(1<<k);mask++)
        {
            //cout<<(1<<k)<<endl;
            ll x = (num/chk(mask));
            if(cnt%2==1)
            {
                ans += x;
            }
            else ans -= x;
            //cout<<"x: = "<<x<<endl;
        }
        printf("%lld\n",num-ans);
    }
    return 0;
}
