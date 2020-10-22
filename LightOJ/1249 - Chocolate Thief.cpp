#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 2*acos(0.0)
struct A
{
    string name;
    ll vol;
};
bool cmp(A a, A b)
{
    return a.vol>b.vol;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;
        scanf("%d",&n);
        A arr[105];
        set<ll> st;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i].name;
            ll x,y,z;
            scanf("%lld %lld %lld",&x,&y,&z);
            arr[i].vol=x*y*z;
            st.insert(arr[i].vol);
        }
        sort(arr+1,arr+(n+1),cmp);
        if(st.size()>1)
        {
            cout<<"Case "<<a<<": "<<arr[1].name<<" took chocolate from "<<arr[n].name<<"\n";
        }
        else cout<<"Case "<<a<<": no thief"<<"\n";


    }
    return 0;
}
