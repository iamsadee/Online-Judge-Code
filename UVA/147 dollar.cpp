#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double amount;
ll dp[13][30005];
vector<ll> arr;
ll make=0;
ll rec(int pos,ll sum)
{
    if(pos>=11)
    {
        if(sum==0)
        {
            return 1;
        }
        else return 0;
    }
    if(sum==0)
        return 1;
    else if(sum<0)
        return 0;
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    ll ans=0;
    ans += rec(pos,sum-arr[pos])+rec(pos+1,sum);
    return dp[pos][sum]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    arr.push_back(10000);
    arr.push_back(5000);
    arr.push_back(2000);
    arr.push_back(1000);
    arr.push_back(500);
    arr.push_back(200);
    arr.push_back(100);
    arr.push_back(50);
    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(5);
    reverse(arr.begin(),arr.end());
        memset(dp,-1,sizeof dp);
    while(cin>>amount)
    {
        if(amount==0.00)
            break;
        double banabe=(amount*100.0);
        make=(banabe);
        while(make%5!=0)
        {
            make++;
        }
        ll ans=rec(0,make);
        if(amount>=100.00)
        {
            printf("%.2lf",amount);
        }
        else if(amount>=10.00)
        {
            printf(" %.2lf",amount);
        }
        else printf("  %.2lf",amount);
        printf("%17lld\n",ans);
    }
    return 0;
}
