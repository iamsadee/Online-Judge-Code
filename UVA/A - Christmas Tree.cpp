#include<bits/stdc++.h>
using namespace std;
int k;
vector<int> node[1005];
bool vis[1005];
//vector<int> arr[1005];
int dfs(int x,int pv)
{
    vis[x]=1;
    if(node[x].size()==1 && pv==node[x][0])
        {
           return 1;
        }
    else if(node[x].size()<=k)
        return 1;
    vector<int> arr;
    for(int j=0;j<node[x].size();j++)
    {
        int y=node[x][j];
        if(vis[y]==0)
        {
            arr.push_back( dfs(y,x));
        }
    }
    sort(arr.begin(),arr.end(),greater<int>());
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum += arr[i];
    }
    return 1+sum;
}
void clr(int n)
{
    for(int i=1;i<=n;i++)
    {
        node[i].clear();
        vis[i]=0;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int n;
        scanf("%d %d",&n,&k);
        clr(n);
        for(int j=1; j<n; j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            node[x].push_back(y);
            node[y].push_back(x);
        }
        node[1].push_back(0);
        vis[0]=1;
        int ans=dfs(1,0);
        printf("Case %d: %d\n",i,ans);




    }


    return 0;
}
