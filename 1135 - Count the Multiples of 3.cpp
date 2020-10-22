#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg
{
    int zero,one,two,prop;
};
static seg tree[400005];
void change(int node,int a,int b)
{
    tree[node].one=tree[a].one + tree[b].one;
    tree[node].two=tree[a].two + tree[b].two;
    tree[node].zero=tree[a].zero + tree[b].zero;
}
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].zero +=1 ;
        return;
    }
    int mid=(b+e)/2;
    int left=2*node;
    int right=left +1;
    build(left,b,mid);
    build(right,mid+1,e);
    change(node,left,right);
}
void lazy(int node,int b,int e)
{
    if(tree[node].prop !=0)
    {
        if(b!=e)
        {
            tree[node*2].prop += tree[node].prop;
            tree[node*2 +1].prop += tree[node].prop;
        }
        if(tree[node].prop%3==1)
        {
            int temp=tree[node].one;
            tree[node].one=tree[node].zero;
            tree[node].zero=tree[node].two;
            tree[node].two=temp;
        }
        else if(tree[node].prop%3==2)
        {
            int temp=tree[node].two;
            tree[node].two=tree[node].zero;
            tree[node].zero=tree[node].one;
            tree[node].one=temp;

        }
        tree[node].prop=0;
    }
}
void update(int node , int b,int e,int i,int j)
{
    lazy(node,b,e);
    if(b>j || e<i)
        return ;
    if(b>=i && e<=j)
    {
        tree[node].prop +=1;
        lazy(node,b,e);
        return ;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=2*node+1;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    change(node,left,right);
}
int query(int node,int b,int e,int i,int j)
{
    lazy(node,b,e);
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node].zero;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    int x1=query(left,b,mid,i,j);
    int x2=query(right,mid+1,e,i,j);
    return x1+x2;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        memset(tree,0,sizeof tree);
        int n,q;
        scanf("%d %d",&n,&q);
        build(1,0,n-1);
        printf("Case %d:\n",i);
        for(int j=1;j<=q;j++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            if(x==0)
            {
                update(1,0,n-1,y,z);
            }
            else
            {
                int ans=query(1,0,n-1,y,z);
                printf("%d\n",ans);
            }
        }


    }
    return 0;
}

