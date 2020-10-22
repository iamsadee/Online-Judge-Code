#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[105][105];
string a,b;
int n,m;
int fun(int l,int r)
{
    if(l>=n || r>=m)
    {
        return 0;
    }
    if(dp[l][r]!=-1)
        return dp[l][r];
    int res=0;
    if(a[l]==b[r])
    {
        res=max(res,1+fun(l+1,r+1));
    }
    res=max(res,fun(l+1,r));
    res=max(res,fun(l,r+1));
    return dp[l][r]=res;
}
string ans;
vector<int> node[3][27];
int bin(int o,int p,int req)
{
    int low=0;
    int high=node[o][p].size()-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(node[o][p][mid]>=req)
        {
            ans=node[o][p][mid];
            high=mid-1;
        }
        else low=mid+1;
    }
    //cout<<ans<<endl;
    return ans;
}
void path(int l,int r)
{
    if(l>=n || r>=m)
        return;
    for(char aa='a';aa<='z';aa++)
    {
        int x=aa-97;
        int pos=bin(0,x,l);
        int pos1=bin(1,x,r);
        //cout<<pos<<" "<<pos1<<endl;
        if(pos!=-1 && pos1!=-1)
        {
            if(dp[l][r]==dp[pos][pos1])
            {
                //chk=1;
                ans.push_back(aa);
                path(pos+1,pos1+1);
                break;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int ks=1;
    while(t--)
    {
        cin>>a>>b;
        n=a.size();
        m=b.size();
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<26;j++)
            {
                node[i][j].clear();
            }
        }
        memset(dp,-1,sizeof dp);
        int res=fun(0,0);
        if(res==0)
        {
            cout<<"Case "<<ks<<": "<<":(\n";
            ks++;
        }
        else
        {
           ans.clear();
           for(int i=0;i<n;i++)
           {
               int x=a[i]-97;
               node[0][x].push_back(i);
           }
           for(int i=0;i<m;i++)
           {
               int x=b[i]-97;
               node[1][x].push_back(i);
           }
           path(0,0);
           cout<<"Case "<<ks<<": "<<ans<<"\n";
           ks++;
        }
    }
    return 0;
}
