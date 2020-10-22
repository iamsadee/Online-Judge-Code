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
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin>>n)
    {
        ll x;
        arr.clear();
        tmp.clear();
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            arr.push_back(x);
        }
        n=arr.size();
        tmp.push_back(0);
        int len=0;
        int A1[15000],A2[15000];
        A1[0]=len+1;
        for(int i=1; i<n; i++)
        {
            int pos=tmp[tmp.size()-1];
            if(arr[pos]<arr[i])
            {
                len++;
                tmp.push_back(i);
                //path[i]=pos;
            }
            else if(arr[i]<arr[tmp[0]])
            {
                tmp[0]=i;
            }
            else
            {
                bin(i);
            }
            A1[i]=len+1;
            //cout<<tmp.size()<<endl;
        }
        tmp.clear();
        tmp.push_back(n-1);
        len=0;
        A2[n-1]=len+1;
        int k=0;
        for(int i=n-2;i>=0;i--)
        {
            int pos=tmp[tmp.size()-1];
            if(arr[pos]<arr[i])
            {
                len++;
                tmp.push_back(i);
                //path[i]=pos;
            }
            else if(arr[i]<arr[tmp[0]])
            {
                tmp[0]=i;
            }
            else
            {
                bin(i);
            }
            k++;
            A2[i]=len+1;
        }
        int mx=0;
        A2[n]=0;
        for(int i=0;i<n;i++)
        {
            int mn=min(A1[i],A2[i]);
            mx=max(mx,(2*mn)-1);
        }
        cout<<mx<<endl;
    }
    return 0;
}
