#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[50005];
struct A
{
    ll sum,prefix,suffix,ans;
} tree[150005];
void build(int node,int b,int e)
{
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
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prefix=max(tree[left].prefix,tree[left].sum+tree[right].prefix);
    tree[node].suffix=max(tree[right].suffix,tree[left].suffix+tree[right].sum);
    tree[node].ans=max(tree[left].ans,tree[left].suffix+tree[right].prefix);
    tree[node].ans=max(tree[right].ans,tree[node].ans);
}
A query(int node,int b,int e,int i,int j)
{
    if(j<b || e<i)
    {
        A a;
        a.sum=0;
        a.ans=-1e10;
        a.prefix=-1e10;
        a.suffix=-1e10;
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
    A res2;
    res2.sum=res1.sum+res.sum;
    res2.prefix=max(res.prefix,res1.prefix+res.sum);
    res2.suffix=max(res.suffix+res1.sum,res1.suffix);
    res2.ans=max(res1.ans,res.ans);
    res2.ans=max(res2.ans,res.suffix+res1.prefix);
    return res2;
}
void update(int node,int b,int e,int i)
{
    if(e<i || b>i)
    {
        return ;
    }
    if(b==e && b==i)
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
    update(left,b,mid,i);
    update(right,mid+1,e,i);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prefix=max(tree[left].prefix,tree[left].sum+tree[right].prefix);
    tree[node].suffix=max(tree[right].suffix,tree[left].suffix+tree[right].sum);
    tree[node].ans=max(tree[left].ans,tree[left].suffix+tree[right].prefix);
    tree[node].ans=max(tree[right].ans,tree[node].ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
        int x,y,id;
        cin>>id>>x>>y;
        if(id==0)
        {
            arr[x]=y;
            update(1,1,n,x);
        }
        else
        {
            A a=query(1,1,n,x,y);
            cout<<a.ans<<"\n";
        }
    }
    return 0;
}
