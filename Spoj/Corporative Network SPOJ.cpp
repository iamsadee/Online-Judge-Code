#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll par[20005];
ll sz[20005];
ll res[20005];
int findd(int x)
{
    if(par[x]==x)
        return x;
    int y=par[x];
    par[x]=findd(par[x]);
    res[x] += res[y];
    return par[x];
}
void unionn(int x,int y)
{
    int u=findd(x);
    int v=findd(y);
    if(u!=v)
    {
        par[x] = y;
        res[x] =  ( abs(x-y))%1000;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            par[i]=i;
            sz[i]=1;
            res[i]=0;
        }
        char ch;
        while(cin>>ch)
        {
            if(ch=='O')
                break;
            if(ch=='E')
            {
                int x;
                cin>>x;
                findd(x);
                cout<<res[x]<<"\n";
            }
            else
            {
                int x,y;
                cin>>x>>y;
                unionn(x,y);
            }
        }

    }
    return 0;
}

