#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[12][105];
ll arr[12][105];
int m,n;
ll fun(int i,int j)
{
    i=i%m;
    if(i<0)
    {
        i+=m;
    }
    if(j==n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ret1=arr[i][j]+fun(i-1,j+1);
    ll ret2=arr[i][j]+fun(i,j+1);
    ll ret3=arr[i][j]+fun(i+1,j+1);
    ll ans=min(ret1,ret2);
    ans=min(ret3,ans);
    return dp[i][j]=ans;
}
vector<int> ans1;
struct A
{
    string ch;
    ll val;
};
void path(int i,int j)
{
    i=i%m;
    if(i<0)
    {
        i+=m;
    }
    if(j==n)
        return ;
    ans1.push_back(i);
    int tmp=i-1;
    tmp %=m;
    if(tmp<0) tmp +=m;
    int tm=i+1;
    ll ret1=dp[tmp][j+1];
    ll ret2=dp[i][j+1];
    tm %=m;
    ll ret3=dp[tm][j+1];
    ll ans=min(ret1,ret2);
    ans=min(ret3,ans);
    //cout<<ans<<endl;
    if(ret1==ans && ret1==ret2 && ret2==ret3)
    {
        int mn=min(tmp,tm);
        mn=min(mn,i);
        //ans1.push_back(mn);
        path(mn,j+1);
    }
    else if(ret1==ret2 && ret2==ans)
    {
        int mn=min(i,tmp);
        //ans1.push_back(mn);
        path(mn,j+1);
    }
    else if(ret1==ret3 && ret3==ans)
    {
        int mn=min(tmp,tm);
        //ans1.push_back(mn);
        path(mn,j+1);
    }
    else if(ret2==ret3 && ans==ret3)
    {
        int mn=min(i,tm);
        //ans1.push_back(mn);
        path(mn,j+1);
    }
    else if(ret1==ans)
    {
        //ans1.push_back(tmp);
        path(tmp,j+1);
    }
    else if(ret2==ans)
    {
        //ans1.push_back(i);
        path(i,j+1);
    }
    else
    {
        //ans1.push_back(tm);
        path(tm,j+1);
    }
}
bool cmp(A a, A b)
{
    if(a.val==b.val)
    {
        return a.ch<b.ch;
    }
    return a.val<b.val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>m>>n)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>arr[i][j];
            }
        }
        vector<A> lex;
        ll mn=1e18;
        for(int i=0; i<m; i++)
        {
            memset(dp,-1,sizeof dp);
            ll res=fun(i,0);
            ans1.clear();
            path(i,0);
            string ret;
            for(int j=0;j<ans1.size();j++)
            {
                ret.push_back(ans1[j]+'0');
            }
            A a;
            a.val=res;
            a.ch=ret;
            lex.push_back(a);
        }
        sort(lex.begin(),lex.end(),cmp);
        string ret=lex[0].ch;
        //cout<<ret<<endl;
        int k=ret.size();
        for(int i=0;i<k;i++)
        {
            int x=ret[i]-'0';

            cout<<x+1;
            if(i==k-1) cout<<endl;
            else cout<<" ";
        }
        cout<<lex[0].val<<endl;
    }
    return 0;
}
