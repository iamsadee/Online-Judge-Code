#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> st;
ll binary(ll x)
{
    ll low , mid,high,ans=st.size()-1;
    low=0;
    high=st.size()-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(st[mid]<x)
        {
            //ans=mid;
            low=mid+1;
        }
        else{
                ans=mid;
                high=mid-1;
        }
    }
    return ans;
}
int main()
{
    int n,i,j,k=1,m;
    ll arr[1002];
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        st.clear();
        st.push_back(0);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                st.push_back(arr[i]+arr[j]);
            }
        }
        sort(st.begin(),st.end());
        scanf("%d",&m);
        ll x;
        printf("Case %d:\n",k++);
        for(j=1;j<=m;j++)
        {
            scanf("%lld",&x);
            ll y=binary(x);
            if(y==0)
            {
                y+=2;
            }
            else if(y==1)
            {
                y+=1;
            }
            ll a=abs(x-st[y]);
            ll b=abs(x-st[y-1]);
            if(a<=b)
            {
                printf("Closest sum to %lld is %lld.\n",x,st[y]);
            }
            else
            {
                printf("Closest sum to %lld is %lld.\n",x,st[y-1]);
            }
        }
    }
    return 0;
}
