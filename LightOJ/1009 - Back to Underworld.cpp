#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll al[100005];
bool vis[20005];
int cnt=0;
int a=0,b=0;
vector<int> node[20005];
void dfs(int src,int A)
{
    if(A%2==0)
    {
        a++;
    }
    else b++;
    vis[src]=1;
    int i;
    for(i=0; i<node[src].size(); i++)
    {
        int y=node[src][i];
        if(vis[y]==0)
        {
            //cnt++;
            dfs(y,A+1);
        }
    }
    return ;
}
void clr()
{
    for(int i=1; i<=20000; i++)
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
        scanf("%d",&n);
        clr();
        bool arr[20005];
        memset(arr,0,sizeof arr);
        vector<int> val;
        for(int j=1; j<=n; j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(arr[x]==0)
            {
                arr[x]=1;
                val.push_back(x);
            }
            if(arr[y]==0)
            {
                arr[y]=1;
                val.push_back(y);
            }
            node[x].push_back(y);
            node[y].push_back(x);
        }
        //memset(vis,0,sizeof vis);
        int z=val.size();
        int ans=0;
        vis[0]=1;
        cnt=0;
        for(int j=0; j<z; j++)
        {
            int x=val[j];
            //cout<<"x : "<<x<<endl;
            if(vis[x]==0)
            {
                node[x].push_back(0);
                a=0,b=0;
                dfs(x,0);
                //cnt=0;
                //cout<<cnt<<endl;
                cnt += max(a,b);
            }
        }
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}
