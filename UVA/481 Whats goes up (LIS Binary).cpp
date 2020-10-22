#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> arr,tmp;
int path[200005];
void bin(int pos)
{
    int low=0;
    int high=tmp.size()-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[tmp[mid]]<arr[pos])
        {
            low=mid+1;
        }
        else
        {
            ans=mid;
            high=mid-1;
        }
    }
    tmp[ans]=pos;
    if((ans-1)>=0)
    {
        path[pos]=tmp[ans-1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(path,-1,sizeof path);
    ll x;
    arr.clear();
    tmp.clear();
    map<ll,int> mp;
    int k=0;
    while(cin>>x)
    {
        arr.push_back(x);
        if(mp[x]==0)
        {
            k++;
            mp[x]=k;
        }
    }
    int n=arr.size();
    tmp.push_back(0);
    int len=0;
    for(int i=1;i<n;i++)
    {
        int pos=tmp[tmp.size()-1];
        if(arr[pos]<arr[i])
        {
            len++;
            tmp.push_back(i);
            path[i]=pos;
        }
        else if(arr[i]<arr[tmp[0]])
        {
            tmp[0]=i;
        }
        else
        {
            bin(i);
        }
        //cout<<tmp.size()<<endl;
    }
    //cout<<n<<endl;
    vector<ll> ans;
    int y=tmp[tmp.size()-1];
    ans.push_back(arr[y]);
    while(path[y]!=-1)
    {
        ans.push_back(arr[path[y]]);
        y=path[y];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    cout<<"-"<<endl;
    //cout<<len+1<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
