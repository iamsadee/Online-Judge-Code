#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        static ll arr[200005];
        ll k,c,n;
        scanf("%lld %lld %lld %lld",&k,&c,&n,&arr[1]);
        ll mod=1000007;
        static ll qsum[200005];
        qsum[0]=0;
        qsum[1]=arr[1];
        for(int i=2;i<=n;i++)
        {
            arr[i]=(arr[i-1]%mod * k%mod)%mod;
            arr[i]=(arr[i]%mod + c%mod)%mod;
        }
        ll sum=0;
        sort(arr,arr+(n+1));
        for(int i=1;i<=n;i++)
        {
            qsum[i]= qsum[i-1]+arr[i];
        }
        for(int i=1;i<n;i++)
        {
            ll x=qsum[n]-qsum[i];
            ll y=x-(n-i)*arr[i];
            sum +=y;
        }
        printf("Case %d: %lld\n",a,sum);
    }
    return 0;
}
