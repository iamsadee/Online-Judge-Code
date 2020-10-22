#include<bits/stdc++.h>
using namespace std;
map<string,string> par;
map<string,int> arr;
string khuj(string x)
{
    if(par[x]==x)
        return x;
    return par[x]=khuj(par[x]);
}
void makeset(string a,string b)
{
    string u,v;
    u=khuj(a);
    v=khuj(b);
    if(u!=v)
    {
        arr[khuj(par[u])] += arr[par[v]];
        par[khuj(par[v])] = khuj(par[u]);
    }
}
int main()
{
    int n,m,i,j,k;
    while(scanf("%d %d",&n,&m)==2)
    {
        par.clear();
        arr.clear();
        getchar();
        if(n==0 && m==0)
            break;
        string ch[5001],a,b;
        for(i=1;i<=n;i++)
        {
            cin>>ch[i];
            par[ch[i]]=ch[i];
            arr[ch[i]]=1;
        }
        for(j=1;j<=m;j++)
        {
            cin>>a>>b;
            makeset(a,b);
        }
        int mx=0;
        for(i=1;i<=n;i++)
        {
            mx=max(arr[ch[i]],mx);
        }
        printf("%d\n",mx);
        getchar();
        getchar();
    }
    return 0;
}
