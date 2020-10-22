///UVA - 10192 LCS vacation

#include<bits/stdc++.h>
using namespace std;
int dp[102][102];
string a,b;
int rec(int i,int j)
{
    if(a[i]=='\0' || b[j]=='\0')
        return 0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=0,x,y;
    if(a[i]==b[j])
    {
        ans = 1+rec(i+1,j+1);
    }
    else
    {
        x=rec(i+1,j);
        //cout<<"x= "<<x<<endl;
        y=rec(i,j+1);
        ans=max(x,y);
        //cout<<"Y= "<<y<<endl;
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    int j=1;
    while(getline(cin,a))
    {
        if(a=="#" && a.size()==1)
            break;
        getline(cin,b);
        memset(dp,-1,sizeof dp);
        printf("Case #%d: you can visit at most %d cities.\n",j++,rec(0,0));
    }
    return 0;
}
