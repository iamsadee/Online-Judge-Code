#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll arr[100005];
struct info{
    ll sum,prop;
}tree[400005];
/*void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        return ;
    }
    int left=2*node;
    int right=2*node +1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}*/
void update(int node,int b,int e,int i,int j,ll x)
{
    if(j<b || e<i)
        return ;
    if(i<=b && e<=j)
    {
        tree[node].sum += ((ll)(e-b+1)*x);
        tree[node].prop += x;
        return ;
    }
    int left=2*node;
    int right=(2*node) +1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum = tree[left].sum + tree[right].sum + ((ll)(e-b+1)*tree[node].prop);
}
ll query(int node,int b,int e,int i,int j,ll carry=0)
{
    if(j<b || e<i)
        return 0;
    if(i<=b && e<=j)
    {
        return tree[node].sum+carry*(e-b+1);
    }
    int left=2*node;
    int right=2*node +1;
    int mid=(b+e)/2;
    ll res1=query(left,b,mid,i,j,carry+tree[node].prop);
    ll res2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return res1+res2;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        memset(tree,0,sizeof tree);
        //build(1,0,n-1);
        printf("Case %d:\n",i);
        for(int j=0;j<q;j++)
        {
            int x;
            scanf("%d",&x);
            if(x==0)
            {
                int y,z;
                ll value;
                scanf("%d %d %lld",&y,&z,&value);
                update(1,0,n-1,y,z,value);
            }
            else
            {
                int y,z;
                scanf("%d %d",&y,&z);
                ll res=query(1,0,n-1,y,z,0);
                printf("%lld\n",res);
            }
        }
    }
    return 0;
}
