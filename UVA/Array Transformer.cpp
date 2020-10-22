#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll u;
ll arr[300005];
vector<ll> node[550];
int blcksz;
int query(int l,int r,ll v)
{
    int cnt=0;
    while(l<r && l%blcksz!=0 && l!=0)
    {
        if(arr[l]<v)
        {
            cnt++;
        }
        l++;
    }
    while((l+blcksz) <=r)
    {
        std::vector<ll>::iterator low;
        low=std::lower_bound (node[l/blcksz].begin(),node[l/blcksz].end(), v);
        cnt += ((low-node[l/blcksz].begin()));
        l += blcksz;
    }
    while(l<=r)
    {
        if(arr[l]<v)
        {
            cnt++;
        }
        l++;
    }
    return cnt;
}
void update(int l,int r,ll u,ll v,int p)
{
    int k=query(l,r,v);
    //cout<<k<<endl;
    ll val=(u*k)/(r-l+1);
    int blckid=p/blcksz;
    ll old=arr[p];
    //cout<<old<<" "<<p<<" "<<blckid<<" "<<blcksz<<" "<<val<<endl;
    for(int i=0;i<node[blckid].size();i++)
    {
        if(node[blckid][i]==old)
        {
            //cout<<"old "<<old<<endl;
            node[blckid][i]=val;
            break;
        }
    }
    sort(node[blckid].begin(),node[blckid].end());
    arr[p]=val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>u;
    blcksz=sqrt(n);
    int k=-1;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(i%blcksz==0)
        {
            k++;
        }
        node[k].push_back(arr[i]);
    }
    for(int i=0; i<=k; i++)
    {
        sort(node[i].begin(),node[i].end());
    }
    for(int i=1; i<=m; i++)
    {
        int l,r,p;
        ll v;
        cin>>l>>r>>v>>p;
        update(l-1,r-1,u,v,p-1);
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\n";
    }

    return 0;
}
