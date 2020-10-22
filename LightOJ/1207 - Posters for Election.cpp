#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static ll tree[600005];
void update(int node,int b,int e,int i,int j,ll x,ll y)
{
    if(j<b || e<i)
        return ;
    if(i<=b && e<=j)
    {
        tree[node]=x;
        //cout<<i<<" "<<j<<endl;
        return ;
    }
    int left=2*node;
    int right=(2*node) +1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x,y);
    update(right,mid+1,e,i,j,x,y);
}
ll mx;
void query(int node,int b,int e,int i,int j,ll x=0)
{
    if(j<b || e<i)
            return ;
    if(i<=b && e<=j)
    {
        mx=max(mx,tree[node]);
        return ;
    }
    int left=2*node;
    int right=2*node +1;
    int mid=(b+e)/2;
    mx=max(mx,tree[node]);
    query(left,b,mid,i,j,x);
    query(right,mid+1,e,i,j,x);

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int o=1;o<=t;o++)
    {
        int n,q;
        scanf("%d",&n);
        memset(tree,0,sizeof tree);
        //build(1,0,n-1);
        //printf("Case %d:\n",i);
        ll z=0;
        for(int i=1;i<=n;i++)
        {
            ll x,y;
            scanf("%lld %lld",&x,&y);
            z=max(z,x);
            z=max(z,y);
            update(1,1,2*n,x,y,i,0);
        }
        set<ll> st;
        for(int i=1;i<=z;i++)
        {
            mx=0;
            query(1,1,2*n,i,i,0);
            if(mx!=0) st.insert(mx);
        }
        mx=st.size();
        printf("Case %d: %lld\n",o,mx);
    }
    return 0;
}
