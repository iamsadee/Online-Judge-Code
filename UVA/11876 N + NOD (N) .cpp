#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> arr;
ll divisor(ll n)
{
    ll x=sqrt(n);
    int i;
    ll cnt=0;
    for(i=1;i<=x;i++)
    {
        if(n%i==0)
        {
            cnt++;
            if((n%(n/i)) ==0 && i!=(n/i))
            {
                cnt++;
            }
        }
    }
    return cnt;
}
ll binary(ll x)
{
    ll low=0,high=arr.size()-1,mid,ans=-1;
    while(low<=high)
    {
        mid=low+((high-low)/2);
        if(arr[mid]>=x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
            ans=mid;
        }

    }
    return ans;
}
ll binary_1(ll x)
{
    ll low=0,high=arr.size()-1,mid,ans=-1;
    while(low<=high)
    {
        mid=low+((high-low)/2);
        if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
            ans=mid;
        }

    }
    return ans;
}
int main()
{
    ll a,b;
    //ll n[100000];
    //n[0]=1;
    arr.push_back(1);
    for(int i=1;;i++)
    {
        ll x= arr[i-1]+divisor(arr[i-1]);
        //cout<<n[i]<<endl;
        arr.push_back(x);
        if(x>1000005)
        {
            //cout<<x<<endl;
            break;
        }
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld %lld",&a,&b);
        ll x,y;
        x=binary(a);
        y=binary_1(b);
       // cout<<x<<' '<<y<<endl;
        printf("Case %d: %lld\n",i,(y-x));
    }
    return 0;
}
