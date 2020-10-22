#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int dp[102][10310];
int arr[105],p[105];
int fun(int i,int sum)
{
    if(sum>m && m<1800)
        return INT_MIN;
    if(sum>(m+200))
        return INT_MIN;
    if(i>=n)
    {
        if(sum>m && sum<=2000)
            return INT_MIN;
        return 0;
    }
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    int res1=0,res2=0;
    res1=p[i]+fun(i+1,sum+arr[i]);
    res2=fun(i+1,sum);
    return dp[i][sum]=max(res1,res2);
}
/*vector<int> ans;
void path(int i,int sum)
{
    if(i>=n)
        return ;
    if(sum>m)
        return ;
    if((p[i]+fun(i+1,sum+arr[i]))>=fun(i+1,sum))
    {
        if(sum+arr[i]<=m){
        ans.push_back(i);}
        path(i+1,sum+arr[i]);
    }
    else if(p[i]+fun(i+1,sum+arr[i])>fun(i+1,sum))
    {
        path(i+1,sum);
    }
    else
    {
        path(i+1,sum+arr[i]);
        path(i+1,sum);
    }
}*/
int main()
{
    int i;
    while(scanf("%d %d",&m,&n)==2)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&arr[i],&p[i]);
        }
        memset(dp,-1,sizeof dp);
        int chk=0;
        int x=fun(0,0);
        cout<<x<<endl;
    }
    return 0;
}
