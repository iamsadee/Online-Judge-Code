#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
vector<int> node[100005];
int n;
ll arr[105];
bool vis[100005];
double dp[100005];
double fun(int pos)
{
    if(pos==1)
    {
        return 1;
    }
    if(vis[pos])
        return dp[pos];
    double res=0;
    int rem=node[pos].size();
    //cout<<rem<<" "<<pos<<endl;
    double prob=(1.0/(rem*1.0));
    //cout<<prob<<endl;
    for(int i=0;i<rem;i++)
    {
        res=res+(prob*(1+fun(pos/node[pos][i])));
    }
    vis[pos]=1;
    return dp[pos]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);
    for(int i=1;i<=1e5;i++)
    {
        int sq=sqrt(i);
        for(int j=2;j<=sq;j++)
        {
            if(i%j==0)
            {
                node[i].push_back(j);
                int x=i/j;
                if(x!=j)
                {
                    node[i].push_back(x);
                }
            }
        }
        node[i].push_back(i);
    }
    //cout<<node[2].size()<<endl;
    int t;
    cin>>t;
    int ks=1;
    memset(vis,0,sizeof vis);
    while(t--)
    {
        cin>>n;
        double res=fun(n);
        if(n==1) res=0;
        printf("Case %d: %0.6lf\n",ks,res);
        ks++;
    }
    return 0;
}
