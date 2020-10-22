#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> tmp;
int n;
int dp[105][105];
int fun(int l,int r)
{
    if(l==r)
    {
        return 1;
    }
    if(dp[l][r]!=-1)
        return dp[l][r];
    int res=1+fun(l+1,r);
    for(int i=l+1;i<=r;i++)
    {
        if(tmp[l]==tmp[i])
        {
            res=min(res,fun(l+1,i-1)+fun(i,r));
        }
    }
    return dp[l][r]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1;ks<=t;ks++)
    {
        cin>>n;
        tmp.clear();
        int arr[n];
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x!=prev)
            {
                prev=x;
                tmp.push_back(x);
            }
        }
        n=tmp.size()-1;
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        cout<<"Case "<<ks<<": "<<fun(0,n)<<"\n";


    }
    return 0;
}
