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
static ll par[405];
ll findd(ll x)
{
    if(par[x]==x)
        return x;
    return par[x]=findd(par[x]);
}
ll mst(ll m)
{
    ll cost=0;
    int n=arr.size();
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        par[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        ll u,v;
        u=findd(arr[i].u);
        v=findd(arr[i].v);
        if(u!=v)
        {
            cnt++;
            par[u]=v;
            cost += arr[i].w;
            //cout<<cost<<endl;
            if(cnt==(m-1))
            {
                break;
            }
        }
    }
    if(cnt==m-1) return cost;
    else return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    int l=0;
    int t;
    cin>>t;
    //cin.ignore();
    for(int l=1;l<=t;l++)
    {
        cin>>n;
        arr.clear();
        cin.ignore();
        map<string,int> mp;
        map<string,bool> chk;
        graph get;
        int j=1;
        for(int i=1;i<=n;i++)
        {
            string a,b;
            int w;
            cin>>a>>b;
            cin>>w;
            if(chk[a]==0)
            {
                chk[a]=1;
                mp[a]=j++;
            }
            if(chk[b]==0)
            {
                chk[b]=1;
                mp[b]=j++;
            }
            get.u=mp[a];
            get.v=mp[b];
            get.w=w;
            arr.push_back(get);
        }
        string a;
        sort(arr.begin(),arr.end(),comp);
        ll ans = mst(j-1);
        if(ans!=-1)
        {
            cout<<"Case "<<l<<": "<<ans<<'\n';
        }
        else cout<<"Case "<<l<<": "<<"Impossible"<<'\n';
        //cin.ignore();
    }
    return 0;
}
