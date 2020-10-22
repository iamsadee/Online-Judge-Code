#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A
{
    ll l,r;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        vector<A> point;
        set<ll> st;
        for(int i=1;i<=n;i++)
        {
            A a;
            scanf("%lld %lld",&a.l,&a.r);
            point.push_back(a);
            st.insert(a.l);
             st.insert(a.r);
        }
        vector<ll> qu;
        for(int i=1;i<=q;i++)
        {
            ll x;
            scanf("%lld",&x);
            qu.push_back(x);
            st.insert(x);
        }
        set<ll>::iterator it;
        map<ll,int> mp;
        int k=1;
        static ll arr[300005];
        for(it=st.begin();it!=st.end();it++)
        {
            arr[k]=0;
            mp[(*it)]=k;
            k++;
            arr[k]=0;
            mp[(*it)+1]=k;
            k++;
        }
        //static ll res[300005];
        //res[0]=0;
        for(int i=0;i<n;i++)
        {
            ll x=point[i].l;
            ll y=point[i].r;
            int a=mp[x];
            int b=mp[y+1];
            arr[a]++;
            arr[b]--;
        }
        for(int i=1;i<k;i++)
        {
            arr[i] += arr[i-1];
        }
        printf("Case %d:\n",tc);
        for(int i=0;i<q;i++)
        {
            ll x=qu[i];
            int a=mp[x];
            printf("%lld\n",arr[a]);
        }
    }
    return 0;
}
