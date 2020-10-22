#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct graph{
    ll u,v,w;
};
bool comp(graph a,graph b)
{
    return a.w<b.w;
}
vector<graph> arr;
static ll par[10005];
ll findd(ll x)
{
    if(par[x]==x)
        return x;
    return par[x]=findd(par[x]);
}
int res=0;
ll mst(ll m,ll A)
{
    ll cost=0;
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        ll u,v;
        u=findd(arr[i].u);
        v=findd(arr[i].v);
        if(u!=v)
        {
            cnt++;
            if(cnt==1 && arr[i].w>=2*A)
            {
                cost += 2*A;
                res +=2;
            }
            else if(cnt == 1)
            {
                cost += arr[i].w;
            }
            else if(cnt>1 && arr[i].w>=A)
            {
                cost += A;
                res++;
            }
            else
            {
                cost += arr[i].w;
            }
            par[u]=v;
            if(cnt==(m-1))
            {
                break;
            }
        }
    }
    if(cnt !=m)
    {
        cost += (m-cnt)*A;
        res+= (m-cnt);
    }
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,z;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        arr.clear();
        cin>>n>>m>>z;
        graph get;
        for(int j=1;j<=n;j++)
        {
            par[j]=j;
        }
        for(int j=1;j<=m;j++)
        {
            ll uu,vv,ww;
            cin>>uu>>vv>>ww;
            get.u=uu;
            get.v=vv;
            get.w=ww;
            arr.push_back(get);
        }
        sort(arr.begin(),arr.end(),comp);
        res=0;
        ll ans = mst(n,z);
        cout<<"Case "<<i<<": "<<ans<<' '<<res<<'\n';
    }
    return 0;
}
