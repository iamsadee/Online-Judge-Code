#include<bits/stdc++.h>
using namespace std;
int dp[102],n;
vector<int> arr[102];
int lis(int x)
{
    if(dp[x]!=-1)
        return dp[x];
    int y,i,j,mx=0;
    for(y=0;y<arr[x].size();y++)
    {
        int z=arr[x][y];
            if(lis(z)>mx)
            {
                mx=lis(z);
            }
    }
    return dp[x]=1+mx;
}
void clr(int x)
{
    for(int i=0;i<=x+1;i++)
    {
        arr[i].clear();
    }
}
int main()
{

    int i,j;
    while(cin>>n)
    {
        if(n==0)
            break;
        int x,y;
        clr(n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(j=1;j<=x;j++)
            {
                scanf("%d",&y);
                arr[i].push_back(y);
            }
        }
        memset(dp,-1,sizeof dp);
        int mx=0,chk=0;
        for(i=1;i<=n;i++)
        {
            //mx = max(mx,lis(i));
            if(mx<lis(i))
            {
                mx=lis(i);
                chk=i;
            }
        }
        cout<<chk<<endl;
    }
    return 0;
}
