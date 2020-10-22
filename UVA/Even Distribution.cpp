#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
//bool vis[10005];
set<ll> st;
ll arr[10005];
vector<int> node[10005];
map< pair<int,ll>,bool > mp;
//vector<ll> golu[10005];
void clr(int n)
{
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        node[i].clear();
    }
}
bool bfs(int x,ll gcd)
{
    mp[make_pair(x,gcd)]=1;
    queue<pair<int,ll> > q;
    q.push(make_pair(x,gcd));
    while(!(q.empty()))
    {
        pair<int,ll> pr=q.front();
        int y=pr.first;
        for(int i=0;i<node[y].size();i++)
        {
            int z=node[y][i];
            ll GCD=__gcd(pr.second,arr[z]);
            if(mp[make_pair(z,GCD)]==0)
            {
                mp[make_pair(z,GCD)]=1;
                st.insert(GCD);
                q.push(make_pair(z,GCD));
            }
        }
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin>>n)
    {
        st.clear();
        clr(n);
        int m;
        cin>>m;

        //ll arr[10005];
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
            //cout<<i<<" "<<arr[i]<<endl;
            st.insert(arr[i]);
        }
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            if(mp[make_pair(i,arr[i])]==0)
            {
                bfs(i,arr[i]);
            }

        }
        cout<<st.size()<<endl;

    }
    return 0;
}
