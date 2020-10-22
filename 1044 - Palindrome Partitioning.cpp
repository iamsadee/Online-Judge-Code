#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ch;
ll arr[102];
int n;
int dp[1005];
bool pal[1005][1005];
bool ispal(int i,int j)
{
    int m=j,k=i;
    int ghu=((j-i)+1)/2;
    for(int a=1; a<=ghu; a++)
    {
        if(ch[k]!=ch[m]) return false;
        m--;
        k++;
    }
    return true;
}
void chk()
{
    n=ch.size();
    for(int i=0; i<n; i++)
    {
        pal[i][i]=true;
        for(int j=i+1; j<n; j++)
        {
            pal[i][j]=ispal(i,j);
        }
    }
}
int fun(int l)
{
    if(l>=n)
        return 0;
    if(dp[l]!=-1)
        return dp[l];
    int res=1e9;
    for(int i=l; i<n; i++)
    {
        if(pal[l][i]==true)
        {
            res=min(res,1+fun(i+1));
        }
    }
    res=min(res,1+fun(l+1));
    return dp[l]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        memset(dp,-1,sizeof dp);
        memset(pal,0,sizeof pal);
        cin>>ch;
        chk();
        int res=fun(0);
        cout<<"Case "<<ks<<": "<<res<<"\n";
        //cout<<"Case "<<ks<<": "<<res<<endl;
    }
    return 0;
}
