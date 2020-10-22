///1087 - Diablo
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
ll arr[200005];
ll tree[150005*4];
int n,q;
void inti(int node,int b,int e)
{
    if(b==e)
    {
        if(arr[b]==0)
        {
            tree[node]=0;
        }
        else tree[node]=1;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    inti(left,b,mid);
    inti(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int id=-1;
ll req;
void query(int node,int b,int e)
{
    if(req==1 && b==e)
    {
        id=b;
        return;
    }
    else if(b==e)
    {
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    ll l1=tree[left];
    if(l1<req)
    {
        req -= l1;
        query(right,mid+1,e);
    }
    else
    {
        query(left,b,mid);
    }
    return ;
}
void update(int node,int b,int e,int i,int value)
{
    if(i>e || i<b)
    {
        return ;
    }
    if(i<=b && i>=e)
    {
        tree[node]=value;
        return;
    }
    int left=2*node;
    int right = 2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int t;
    scanf("%d",&t);
    int ks=1;
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
        for(int i=n+1;i<=(n+q);i++) arr[i]=0;
        int nw=n+1;
        inti(1,1,n+q);
        printf("Case %d:\n",ks);
        ks++;
        for(int i=0;i<q;i++)
        {
            char a;
            ll k;
            scanf(" %c %lld",&a,&k);
            //printf("%c\n",a);
            if(a=='a')
            {
                update(1,1,n+q,nw,1);
                arr[nw]=k;
                nw++;
            }
            else
            {
                id=-1;
                req=k;
                //
                query(1,1,n+q);
                //cout<<id<<endl;
                if(id==-1 || arr[id]==0)
                {
                    printf("none\n");
                }
                else
                {
                    printf("%lld\n",arr[id]);
                    arr[id]=0;
                    update(1,1,n+q,id,0);
                }

            }
        }
    }
    return 0;
}
