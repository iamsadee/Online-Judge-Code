#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll arr[100005];
ll tree_prop[400005];
ll tree_sum[400005];
void update(int node,int b,int e,int i,int j,ll x)
{
    if(tree_prop[node]!=-1)
    {
        tree_sum[node]=(e-b+1)*tree_prop[node];
        if(b!=e)
        {
            tree_prop[2*node]=tree_prop[node];
            tree_prop[(2*node)+1]=tree_prop[node];
        }
        tree_prop[node]=-1;
    }
    if(j<b || e<i)
        return ;
    if(i<=b && e<=j)
    {
        tree_sum[node] = ((ll)(e-b+1)*x);
        tree_prop[node] = x;
        if(b!=e)
        {
            tree_prop[2*node]=tree_prop[node];
            tree_prop[2*node+1]=tree_prop[node];
        }
        return ;
    }
    int left=2*node;
    int right=(2*node) +1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree_sum[node] = tree_sum[left] + tree_sum[right] ;
}
ll query(int node,int b,int e,int i,int j,ll carry=0)
{
    if(tree_prop[node]!=-1)
    {
        tree_sum[node]=(e-b+1)*tree_prop[node];
        if(b!=e)
        {
            tree_prop[2*node]=tree_prop[node];
            tree_prop[(2*node)+1]=tree_prop[node];
        }
        tree_prop[node]=-1;
    }
    if(j<b || e<i)
        return 0;
    if(i<=b && e<=j)
    {
        return tree_sum[node];
    }
    int left=2*node;
    int right=2*node +1;
    int mid=(b+e)/2;
    ll res1=query(left,b,mid,i,j,carry+tree_prop[node]);
    ll res2=query(right,mid+1,e,i,j,carry+tree_prop[node]);
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

        memset(tree_sum,0,sizeof tree_sum);
        memset(tree_prop,-1,sizeof tree_prop);
        //build(1,0,n-1);
        printf("Case %d:\n",i);
        for(int j=0;j<q;j++)
        {
            int x;
            scanf("%d",&x);
            if(x==1)
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
                ll x=(z-y+1);
                ll gcd=__gcd(res,x);
                if(res%x==0)
                {
                    res=res/x;
                    printf("%lld\n",res);
                }
                else
                {
                    res=res/gcd;
                    x=x/gcd;
                    printf("%lld/%lld\n",res,x);
                }
            }
        }
    }
    return 0;
}
