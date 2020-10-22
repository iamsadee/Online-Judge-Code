#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double amount;
ll make;
vector<pair<ll,ll> > arr;
ll dp[7][101][505];
ll dp1[7][505];
ll ase=0;
ll rec(int pos,ll sum)
{
    if(pos>=6)
    {
        if(sum==0)
        {
            return 0;
        }
        else return 1e5;
    }
    if(sum==0) return 0;
    if(sum<0) return 1e5;
    if(dp1[pos][sum]!=-1) return dp1[pos][sum];
    ll ret=1+rec(pos,sum-arr[pos].first);
    ll ret1=rec(pos+1,sum);
    return dp1[pos][sum]=min(ret,ret1);
}
ll fun(int pos,int take,ll sum)
{
    //cout<<pos<<" "<<sum<<endl;
    if(pos>=6)
    {
        if(sum==make && take<=arr[pos-1].second)
        {
            return 0;
        }
        else return 1e5;
    }
    if(sum==make && take<=arr[pos].second)
    {
        return 0;
    }
    if(sum>make && sum<=ase)
    {
        return rec(0,(sum-make));
    }
    if(sum>ase)
    {
        return 1e5;
    }
    if(dp[pos][take][sum]!=-1)
        return dp[pos][take][sum];
    ll ret=1e5;
    if((take+1)<=arr[pos].second)
    {
        ret = 1+fun(pos,take+1,sum+arr[pos].first);
    }
    ll ret1=fun(pos+1,0,sum);
    return dp[pos][take][sum]=min(ret,ret1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    ll a,b,c,d,e,f;
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        if(a==0 && b==0 && b==c && c==d && d==e && e==f)
        {
            break;
        }
        cin>>amount;
        make=amount*100;
        while(make%5!=0)
        {
            make++;
        }
        arr.clear();
        ase=0;
        arr.push_back(make_pair(5,a));
        arr.push_back(make_pair(10,b));
        arr.push_back(make_pair(20,c));
        arr.push_back(make_pair(50,d));
        arr.push_back(make_pair(100,e));
        arr.push_back(make_pair(200,f));
        ase += (5*a);
        ase += (10*b);
        ase += (20*c);
        ase += (50*d);
        ase += (100*e);
        ase += (200*f);
        memset(dp,-1,sizeof dp);
        memset(dp1,-1,sizeof dp1);
        ll ans=fun(0,0,0);
        printf("%3d\n",ans);
    }
    return 0;
}
