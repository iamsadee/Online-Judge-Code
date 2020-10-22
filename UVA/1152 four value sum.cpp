#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> ans;
ll binary(ll x)
{
    ll low=0;
    ll high=ans.size()-1;
    ll an =-1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(ans[mid]<x)
        {
             an=mid;
             low=mid+1;
        }
        else if(ans[mid]>=x)
        {
            high=mid-1;
        }
    }
    return an;
}
ll binary_1(ll x)
{
    ll low=0;
    ll high=ans.size()-1;
    ll an =-1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(ans[mid]<=x)
        {
             an=mid;
             low=mid+1;
        }
        else if(ans[mid]>x)
        {
            high=mid-1;
        }
    }
    return an;
}
int main()
{
    int t,n,i,j,k;
    ll arr[4005][5];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        vector<ll> ar;
        ans.clear();
        for(j=0;j<n;j++)
        {
            for(int k=0;k<4;k++)
            {
                scanf("%lld",&arr[j][k]);
            }
        }
        //cout<<"Sadee"<<endl;
        //cout<<n<<endl;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                ll aa=arr[j][0]+arr[k][1];
                ll bb=arr[j][2]+arr[k][3];
                ar.push_back(aa);
                ans.push_back(bb);
            }
        }
        sort(ans.begin(),ans.end());
        ll chk=0;
        for(j=0;j<ar.size();j++)
        {
            ll x=binary(ar[j]*(-1));
            ll y=binary_1(ar[j]*(-1));
            chk += (y-x);
        }
        printf("%lld\n",chk);
        if(i!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
