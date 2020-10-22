#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll arr[100005];
    arr[0]=0;
    int t,i,j,k,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        ll mx=0;
        vector<ll> ar;
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
            ll y=abs(arr[j]-arr[j-1]);
            ar.push_back(y);
            mx = max(mx,y);
        }
        ll mn=mx;
        for(j=0;j<ar.size();j++)
        {
            if(ar[j]==mn)
            {
                mn--;
            }
            else if(ar[j]>mn)
            {
                mx++;
                break;
            }
        }
        printf("Case %d: %lld\n",i,mx);
    }
    return 0;
}
