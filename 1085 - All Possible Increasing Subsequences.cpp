#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
ll tree[400005];
ll mod=1000000007;
ll query(int node,int b,int e, int i,int j)
{
    if(i>e ||j<b)
        return 0;
    if(b>=i && e<=j)
    {
        return (tree[node])%mod;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    ll res1=query(left,b,mid,i,j);
    ll res2=query(right,mid+1,e,i,j);
    return (res1%mod+res2%mod)%mod;
}
void update(int node,int b,int e,int i,ll value)
{
    if(i>e || i<b)
    {
        return ;
    }
    if(i<=b && i>=e)
    {
        tree[node] =(tree[node]%mod+ value%mod)%mod;
        return;
    }
    int left=2*node;
    int right = 2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);
    tree[node]=(tree[left]%mod+tree[right]%mod)%mod;
}
int main()
{

    int n,k,q;
    int t;
    scanf("%d",&t);
    k=-1;
    for(int j=1; j<=t; j++)
    {
        scanf("%d",&n);
        memset(tree,0,sizeof tree);
        ll arr[100005];
        set<ll> st;
        set<ll> ::iterator it;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            st.insert(arr[i]);
        }
        map<ll,int> mp;
        k=0;
        for(it=st.begin();it!=st.end();it++)
        {
            k++;
            mp[(*it)]=k;
        }
        ll ans=0;
        //ll mod=1000000007;
        for(int i=1;i<=n;i++)
        {
            ll x=query(1,1,k,0,mp[arr[i]]-1);
            x++;
            ans = ((ans%mod)+(x%mod))%mod;
            //cout<<ans<<endl;
            update(1,1,k,mp[arr[i]],x);
        }
        printf("Case %d: %lld\n",j,ans);
    }
    return 0;
}
