#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100005],tree[300005];
void build(int node,int b,int e)
{
    if(b==e)
        {
            tree[node]=arr[b];
            return ;
        }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
ll query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(i<=b && j>=e )
    {
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    ll res1=query(left,b,mid,i,j);
    ll res2=query(right,mid+1,e,i,j);
    return res1+res2;
}
void update(int node,int b,int e,int i,ll value)
{
    if(i>e || i<b)
        return ;
    if(i<=b && i>=e)
    {
        tree[node]=value;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);
    tree[node]=tree[left]+tree[right];
}



int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        build(1,0,n-1);
        printf("Case %d:\n",i);
        for(int j=0;j<q;j++)
        {
            int x;
            scanf("%d",&x);
            if(x==1)
            {
                int y;
                scanf("%d",&y);
                printf("%lld\n",arr[y]);
                arr[y]=0;
                update(1,0,n-1,y,0);
            }
            else if(x==2)
            {
                int y;
                ll value;
                scanf("%d %lld",&y,&value);
                arr[y] += value;
                update(1,0,n-1,y,arr[y]);
            }
            else if(x==3)
            {
                int y,z;
                scanf("%d %d",&y,&z);
                ll res=query(1,0,n-1,y,z);
                printf("%lld\n",res);
            }
        }
    }

    return 0;
}
