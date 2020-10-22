#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
ll arr[750000];
ll tree[2144150];
void inti(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=1;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    inti(left,b,mid);
    inti(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int i,int value)
{
    if(i>e || i<b)
    {
        return ;
    }
    if(i<=b && i>=e)
    {
        tree[node]=0;
        return;
    }
    int left=2*node;
    int right = 2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);
    tree[node]=tree[left]+tree[right];
    return;
}
int req;
int id;
void query(int node,int b,int e)
{
    if(req==1 && b==e)
    {
        id=b;
        return ;
    }
    else if(b==e) return;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int j=0;
    for(int i=1;i<=1429431;i+=2)
    {
        j++;
        arr[j]=i;
    }
    inti(1,1,j);
    vector<ll> ans;
    ans.push_back(1LL);
    for(int i=2;i<=1e5;i++)
    {
        req=i;
        id=-1;
        query(1,1,j);
        ll val=arr[id];
        ans.push_back(val);
        //cout<<arr[id]<<" id"<<endl;
        ll pq=0;
        for(int k=val;k<=j;k+=val)
        {
            id=-1;
            req=k-pq;
            pq++;
            query(1,1,j);
            if(id==-1)
                break;
            //cout<<id<<endl;
            update(1,1,j,id,0);
        }
    }
    int t;
    scanf("%d",&t);
    for(int ks=1;ks<=t;ks++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",ks,ans[n-1]);
    }
    return 0;
}
