#include<bits/stdc++.h>
using namespace std;
string a ,b;
int dp[1002][1002];
int rec(int i,int j)
{
    if(i==a.size() || j==b.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int res=0;
    if(a[i]==b[j])
    {
        res = 1+rec(i+1,j+1);
    }
    else
    {
        res = max(rec(i+1,j),rec(i,j+1));
    }
    return dp[i][j]=res;
}
int main()
{
    while(getline(cin,a))
    {
        getline(cin,b);
        memset(dp,-1,sizeof dp);
        printf("%d\n",rec(0,0));
    }
    return 0;
}
