#include<bits/stdc++.h>
using namespace std;
vector<int> node[1000];
queue<int> ar;
int vis[1000],col[1000];

int bfs(int c,int n)
{
    int i,j,k,x,y,z,b;
    col[c]=1;
    b=1;
    ar.empty();
    z=ar.size();
    ar.push(c);
    for(i=0;i<n;i++)
    {
        col[i]=0;
        vis[i]=0;
    }
    while(ar.size()>0)
    {
        z=ar.front();
        x=node[z].size();
        if(vis[z]==0){
           if(col[z]==1)
           {
               b=2;
           }
           else if(col[z]==2)
           {
              b=1;
           }

        for(i=0;i<x;i++)
        {
            y=node[z][i];
                if(col[y]==0)
                {
                    ar.push(y);
                    col[y]=b;
                }
                else if(col[y]==col[z])
                {
                    return 0;
                }
        }
        }
        vis[z]=1;
        ar.pop();
    }
    return 1;
}
int main()
{
    int i,a,b,n,e,c;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        scanf("%d",&e);
        for(i=1;i<=e;i++)
        {
            scanf("%d %d",&a,&b);
            if(i==1)
                c=a;
            node[a].push_back(b);
            node[b].push_back(a);
        }
        a=bfs(c,n);
        if(a==0)
            printf("NOT BICOLORABLE.\n");
        else if(a==1)
            printf("BICOLORABLE.\n");
        for(i=0;i<n;i++)
        {
            node[i].clear();
        }
    }
    return 0;
}
