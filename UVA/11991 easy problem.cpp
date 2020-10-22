#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,k,i,j,m;
    long long arr[100005],x;
    while(scanf("%d %d",&n,&m)==2)
    {
        map<ll,int> mp;
        map< pair<ll,int>,int > ans;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            mp[arr[i]] += 1;
            ans[make_pair(arr[i],mp[arr[i]])] = i;
        }
        for(j=1;j<=m;j++)
        {
            scanf("%d %lld",&k,&x);
            cout<<ans[make_pair(x,k)]<<endl;
        }
    }
    return 0;
}
