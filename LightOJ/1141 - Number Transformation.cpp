#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> prime;
void seive()
{
    for(int i=2;i<=1000;i++)
    {
        int x=sqrt(i);
        bool chk=0;
        for(int j=2;j<=x;j++)
        {
            if(i%j==0)
            {
                chk=1;
            }
        }
        if(chk==0) prime.push_back(i);
    }
}
bool vis[10005];
int bfs(int s,int t)
{
    queue< pair<int,int> > q;
    memset(vis,0,sizeof vis);
    q.push(make_pair(s,0));
    vis[s]=1;
    while(q.size()>0)
    {
        int x=q.front().first;
        int dis=q.front().second;
        q.pop();
        //cout<<x<<" "<<dis<<endl;
        //getchar();
        vis[x]=1;
        if(x==t)
            return dis;
        else if(x<t)
        {
            for(int i=0;prime[i]<x;i++)
            {
                if(x%prime[i]==0 && vis[x+prime[i]]==false && (x+prime[i])<=t)
                {
                    //cout<<(x+prime[i])<<" "<<dis+1<<endl;
                    //getchar();
                    //getchar();
                    q.push(make_pair(x+prime[i],dis+1));
                }
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    seive();
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int s,t;
        scanf("%d %d",&s,&t);
        printf("Case %d: %d\n",i,bfs(s,t));

    }

    return 0;

}
