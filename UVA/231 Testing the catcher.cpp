#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int dp[100005],n;
int lis(int x)
{
    if(dp[x]!=-1)
        return dp[x];
    int y,i,j,mx=0;
    for(y=x+1;y<n;y++)
    {
        if(arr[y]<arr[x])
        {
            if(lis(y)>mx)
            {
                mx=lis(y);
            }
        }
    }
    return dp[x]=1+mx;
}
int main()
{

    int x,y,i,mx,j=0;
    while(scanf("%d",&x)==1)
    {
        arr.clear();
        j++;
        if(x==-1)
            break;
        if(j!=1)
        {
            printf("\n");
        }
        arr.push_back(x);
        while(scanf("%d",&y)==1)
        {
            if(y==-1)
                break;
            arr.push_back(y);
        }
        n=arr.size();
        mx=0;
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++)
        {
            mx=max(mx,lis(i));
        }
        printf("Test #%d:\n",j);
        printf("  maximum possible interceptions: %d\n",mx);
    }
    return 0;
}
