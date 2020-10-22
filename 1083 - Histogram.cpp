#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
ll arr[30005];
ll tree[3*30005];
void inti(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=b;
        //cout<<tree[node]<<endl;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    inti(left,b,mid);
    inti(right,mid+1,e);
    int x=tree[left];
    int y=tree[right];
    if(arr[x]>=arr[y])
    {
        tree[node]=y;
    }
    else
    {
        tree[node]=x;
    }
}
int query(int node,int b,int e,int x,int y)
{
    if(x>e || y<b)
        return 0;
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
    if(arr[a]<arr[c])
    {
        return a;
    }
    else return c;
}
ll mx=-1;
void ans(int i,int j,int n)
{
    if(i>n || j>n || i<1 || j<1)
    {
        return ;
    }
    if(i>j)
        return ;
    int x=query(1,1,n,i,j);
    //cout<<x<<endl<<endl;
    mx=max(mx,arr[x]*(j-i+1));
    ans(i,x-1,n);
    ans(x+1,j,n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    int t;
    cin>>t;
    arr[0]=1e5;
    for(int a=1;a<=t;a++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        inti(1,1,n);
        mx=-1;
        ans(1,n,n);
        cout<<"Case "<<a<<": "<<mx<<"\n";
    }
    return 0;
}
