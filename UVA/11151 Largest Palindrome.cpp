#include<bits/stdc++.h>
using namespace std;
string ch;
int dp[1001][1001];
int lps(int i,int j)
{
    if(i==j)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(ch[i]==ch[j] && i+1==j)
        return 2;
    else if(ch[i]==ch[j])
    {
        return dp[i][j]=lps(i+1,j-1)+2;
    }
    else if(ch[i]!=ch[j])
    {
        return dp[i][j]=max(lps(i+1,j),lps(i,j-1));
    }
}
int main()
{
    int t,i;
    cin>>t;
    getchar();
    for(i=1;i<=t;i++)
    {
        memset(dp,-1,sizeof dp);
        getline(cin,ch);
        int x=lps(0,ch.size()-1);
        cout<<x<<endl;
    }
    return 0;
}

