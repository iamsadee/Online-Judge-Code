///Segment Tree (like GSS)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A
{
    int left,right,ans,sum;
    int lid,rid,sid;
};
A tree[300005];
int arr[100005];
A comp(A x,A y)
{
    A z;
    if(x.lid==-1e5)
    {
        z=y;
    }
    else if(y.lid==-1e5)
    {
        z=x;
    }
    if(x.sid==y.sid)
    {
        z.sum=x.sum+y.sum;
        z.sid=x.sid;
    }
    else
    {
        z.sum=0;
        z.sid=0;
    }
    z.ans=max(x.ans,y.ans);
    if(x.rid==y.lid)
    {
        z.ans=max(z.ans,x.right+y.left);
    }
    z.left=x.left;
    z.lid=x.lid;
    if(x.sid==y.lid)
    {
        z.left=max(z.left,x.sum+y.left);
        z.lid=x.sid;
    }
    z.right=y.right;
    z.rid=y.rid;
    if(x.rid==y.sid)
    {
        z.right=max(z.right,x.right+y.sum);
        z.rid=y.sid;
    }
    return z;
}
void build(int node,int b,int e)
{
    if(b==e)
    {
        A a;
        a.left=1;
        a.lid=arr[b];
        a.rid=arr[b];
        a.right=1;
        a.ans=1;
        a.sum=1;
        a.sid=arr[b];
        tree[node]=a;
        return;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    build(l,b,mid);
    build(r,mid+1,e);
    A a=comp(tree[l],tree[r]);
    tree[node]=a;
}
A query(int node,int b,int e,int i,int j)
{
    if(e<i || b>j)
    {
        A a;
        a.ans=0;
        a.sum=0;
        a.sid=-1e5;
        a.lid=-1e5;
        a.rid=-1e5;
        a.left=0;
        a.right=0;
        return a;
    }
    if(i<=b && e<=j)
    {
        return tree[node];
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    A x1=query(l,b,mid,i,j);
    A x2=query(r,mid+1,e,i,j);
    return comp(x1,x2);
}
int n;
int main()
{
    int t;
    scanf("%d",&t);
    for(int ks=1;ks<=t;ks++)
    {
        int c,q;
        scanf("%d %d %d",&n,&c,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,0,n-1);
        printf("Case %d:\n",ks);
        while(q--)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            l--;
            r--;
            A a=query(1,0,n-1,l,r);
            printf("%d\n",a.ans);
        }
    }
    return 0;
}
