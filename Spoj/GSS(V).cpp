#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[50005];
struct A
{
    ll sum,prefix,suffix,ans;
    ll l,r;
} tree[150005];
inline A operator+(const A&a,const A&b)
{
    A ret;
    ret.l=a.l,ret.r=b.r,ret.sum=a.sum+b.sum;
    ret.prefix=max(a.prefix,a.sum+b.prefix);
    ret.suffix=max(b.suffix,b.sum+a.suffix);
    ret.ans=max(max(a.ans,b.ans),a.suffix+b.prefix);
    return ret;
}
void build(int node,int b,int e)
{
    tree[node].l=b;
    tree[node].r=e;
    if(b==e)
    {
        tree[node].sum=arr[b];
        tree[node].prefix=arr[b];
        tree[node].suffix=arr[b];
        tree[node].ans=arr[b];
        return ;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    build(node*2,b,mid);
    build((node*2)+1,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
A query(int node,int b,int e,int i,int j)
{
    if(j<b || e<i)
    {
        A a;
        a.l=tree[node].l;
        a.r=tree[node].r;
        a.sum=0;
        a.ans=-INT_MAX;
        a.prefix=-INT_MAX;
        a.suffix=-INT_MAX;
        return a;
    }
    if(i<=b && e<=j)
    {
        return tree[node];
    }
    int left=2*node;
    int right=left+1;
    int mid=(b+e)/2;
    A res=query(left,b,mid,i,j);
    A res1=query(right,mid+1,e,i,j);
    return res+res1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        build(1,1,n);
        int m;
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(y1<x2)
            {
                A ansL=query(1,1,n,x1,y1),ansM=query(1,1,n,y1+1,x2-1),ansR=query(1,1,n,x2,y2);
                //cout<<ansM.sum<<" "<<ansR.prefix<<" "<<ansL.suffix<<endl;
                cout<<ansL.suffix+ansM.sum+ansR.prefix<<"\n";
            }
            else
            {
                ll ans=query(1,1,n,x2,y1).ans;
                if(x1<x2)
                {
                    ans=max(ans,query(1,1,n,x1,x2).suffix+query(1,1,n,x2,y2).prefix-arr[x2]);
                }
                if(y2>y1)
                {
                    ans=max(ans,query(1,1,n,x1,y1).suffix+query(1,1,n,y1,y2).prefix-arr[y1]);
                }
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
