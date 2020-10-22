#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    gcd(y,x%y);
}
int main()
{
    ll n,s;
    while(scanf("%lld %lld",&n,&s)==2)
    {
        ll arr[100005];
        int i,j;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        ll l=1,r=0;
        ll sum=0;
        ll mn=1000000;
        while(r<=n)
        {
            if(l>n)
            {
                break;
            }
            if(sum<s)
            {
                sum += arr[r+1];
                //cout<<"r= "<<r<<' '<<sum<<endl;
                r++;
                //cout<<"r= "<<r<<' '<<sum<<endl;
            }
            else if(sum>=s)
            {
                mn = min(mn,r-l+1);
                //cout<<sum<<endl;
                sum -= arr[l];
                //cout<<l<<' '<<sum<<endl;
                l++;

            }
        }
        //cout<<sum<<endl;
        if(mn==1000000)
        {
            mn=0;
        }
        printf("%lld\n",mn);
    }
    return 0;
}
