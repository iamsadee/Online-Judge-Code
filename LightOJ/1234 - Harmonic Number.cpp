#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double sum=0;
    ll mod=1000;
    vector<double> arr;
    arr.push_back(0.0);
    for(ll i=1;i<=1e8;i++)
    {
        sum += double(1.0/(i*1.0));
        if(i%mod==0)
        {
            arr.push_back(sum);
        }
    }
    int t;
    scanf("%d",&t);
    for(int j=1; j<=t; j++)
    {
        ll x;
        scanf("%lld",&x);
        int z=x/1000;
        double res=arr[z];
        ll y=(x-x%1000);
        for(ll k=y+1;k<=x;k++)
        {
            res += (1.0/(k*1.0));
        }
        printf("Case %d: %0.12lf\n",j,res);

    }
    return 0;
}
