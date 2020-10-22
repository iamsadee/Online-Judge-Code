#include<bits/stdc++.h>
using namespace std;
int arr[35],w[35],dp[35][1002],n,t,c;
int fun(int i,int sum)
{
    if(i>=n)
        return 0;
    if(sum<0)
        return 0;
    int res1=0,res2=0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(sum-(arr[i]*c+(arr[i]*2*c))>=0)
            res1 = w[i]+fun(i+1,sum-(arr[i]*c+(arr[i]*2*c)));
    res2=fun(i+1,sum);
    return dp[i][sum]=max(res1,res2);
}
vector<int> ans;
void path(int i,int sum)
{
    if(i>=n)
        return;
    if(sum<=0)
        return ;
    int res1,res2;
    res1=dp[i+1][sum-(arr[i]*c+arr[i]*2*c)];
    res2 =dp[i+1][sum];
    if(w[i]+fun(i+1,sum-(arr[i]*c+(arr[i]*2*c)))>fun(i+1,sum))
    {
        if(sum-arr[i]*c-arr[i]*2*c>=0) ans.push_back(i);
        //cout<<i<<' '<<sum<<' '<<sum-(arr[i]*c+arr[i]*2*c)<<endl;
        path(i+1,sum-(arr[i]*c+(2*c*arr[i])));
    }
    /*else if(w[i]+fun(i+1,sum-(arr[i]*c+(arr[i]*2*c)))<fun(i+1,sum))
    {
        path(i+1,sum);
    }
    else
    {
        path(i+1,sum);
        path(i+1,sum-(arr[i]*c+(2*c*arr[i])));
    }*/
    else path(i+1,sum);
}
int main()
{
    int i,j=1;
    while(scanf("%d %d",&t,&c)==2)
    {
        if(j!=1)
        {
            cout<<endl;
        }
        j++;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&arr[i],&w[i]);
        }
        memset(dp,-1,sizeof dp);
        int x=fun(0,t);
        cout<<x<<endl;
        path(0,t);
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++)
        {
            cout<<arr[ans[i]]<<' '<<w[ans[i]]<<endl;
        }
        ans.clear();
    }
    return 0;
}
