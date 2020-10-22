#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> tree[300005];
int arr[100005];
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].push_back(arr[b]);
        return;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    build(l,b,mid);
    build(r,mid+1,e);
    int i=0;
    int j=0;
    int sz1=tree[l].size();
    int sz2=tree[r].size();
    while(i<sz1 && j<sz2)
    {
        if(tree[l][i]<tree[r][j])
        {
            tree[node].push_back(tree[l][i]);
            i++;
        }
        else
        {
            tree[node].push_back(tree[r][j]);
            j++;
        }
    }
    while(i<sz1)
    {
        tree[node].push_back(tree[l][i]);
        i++;
    }
    while(j<sz2)
    {
        tree[node].push_back(tree[r][j]);
        j++;
    }
}
int query(int node,int b,int e,int i,int j,int val)
{
    if(e<i || b>j)
    {
        return 0;
    }
    if(i<=b && e<=j)
    {
        return upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    int x1=query(l,b,mid,i,j,val);
    int x2=query(r,mid+1,e,i,j,val);
    return x1+x2;
}
int n;
ll binary(int l,int r,int k)
{
    ll low=0;
    ll high=2e9+1;
    ll ans=0;
    while(low<=high)
    {
        ll mid=(low+high)/2LL;
        int ase=query(1,0,n-1,l,r,(int)mid);
        //cout<<mid<<" "<<ase<<" "<<low<<" "<<high<<endl;
        if(ase>=k)
        {
            ans=mid;
            high=mid-1;
        }
        else if(ase<k)
        {
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i] +=1e9;
    }
    build(1,0,n-1);
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        ll res=binary(l-1,r-1,k);
        int x=1e9;
        cout<<res-x<<"\n";
    }
    return 0;
}
