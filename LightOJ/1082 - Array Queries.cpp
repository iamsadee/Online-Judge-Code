#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//int x,y;
ll arr[100005];
ll tree[4*100005];
void inti(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        //cout<<tree[node]<<endl;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    inti(left,b,mid);
    inti(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int x,int y)
{
    if(x>e || y<b)
        return 100009;
    if(b>=x && e<=y)
    {
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int a=query(left,b,mid,x,y);
    int c=query(right,mid+1,e,x,y);
    //cout<<min(a,c)<<endl;
    return min(a,c);
}
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int q;
        int n;
        scanf("%d %d",&n,&q);
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        inti(1,1,n);
        printf("Case %d:\n",i);
        int x,y;
        for(j=1;j<=q;j++)
        {
            scanf("%d %d",&x,&y);
            int ans=query(1,1,n,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
