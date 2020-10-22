#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll arr[100005];
struct info{
    ll sum,prop;
}tree[400005];
void update(int node,int b,int e,int i,int j)
{
    if(j<b || e<i)
        return ;
    if(i<=b && e<=j)
    {
        tree[node].sum += 1;
        tree[node].prop += 1;
        return ;
    }
    int left=2*node;
    int right=(2*node) +1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[node].sum = tree[left].sum + tree[right].sum + (tree[node].prop);
}
ll query(int node,int b,int e,int i,int j,ll carry=0)
{
    if(j<b || e<i)
        return 0;
    if(i<=b && e<=j)
    {
        return tree[node].sum+carry*1;
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
        char ch[100005];
        scanf("%s",ch);
        //getchar();
        n=strlen(ch);
        scanf("%d",&q);
        //cout<<q<<endl;
        memset(tree,0,sizeof tree);
        //build(1,0,n-1);
        printf("Case %d:\n",i);
        for(int j=0;j<q;j++)
        {
            char x;
            scanf(" %c",&x);
            //cout<<x<<endl;
            if(x=='I')
            {
                int y,z;
                ll value=1;
                scanf("%d %d",&y,&z);
                //cout<<y<<" "<<z<<endl;
                //cout<<y<<" "<<z<<endl;
                update(1,1,n,y,z);
            }
            else
            {
                int y;
                scanf("%d",&y);
                ll res=query(1,1,n,y,y,0);
                ll ans=(ch[y-1]-'0')+res;
                printf("%lld\n",ans%2);
            }
        }
    }
    return 0;
}
