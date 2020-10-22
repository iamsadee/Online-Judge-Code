#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
int n;
ll arr[105];
bool vis[105];
double dp[105];
double fun(int pos)
{
    if(pos>=(n-1))
    {
        return arr[pos];
    }
    if(vis[pos])
        return dp[pos];
    double res=0;
    int rem=min((n-1)-pos,6);
    double prob=(1.0/(rem*1.0));
    //cout<<prob<<endl;
    for(int i=1;i<=rem;i++)
    {
        res=res+(prob*(arr[pos]+fun(pos+i)));
    }
    vis[pos]=1;
    return dp[pos]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);
    int t;
    cin>>t;
    int ks=1;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            vis[i]=0;
            cin>>arr[i];
        }
        double res=fun(0);
        printf("Case %d: %0.6lf\n",ks,res);
        ks++;
    }
    return 0;
}
