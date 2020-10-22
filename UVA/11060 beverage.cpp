#include<bits/stdc++.h>
using namespace std;
int deg[101];
int main()
{
    int i=1,j,n,m,k;
    string ch,u,v;
    map<string,int> mp;
    map<int,string> al;
    vector<int> node[101],ans;
    //getchar();
    while(scanf("%d",&n)==1){
        for(j=1;j<=n;j++)
        {
            cin>>ch;
            mp[ch]=j;
            al[j]=ch;
        }
        scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
            cin>>u>>v;
            node[mp[u]].push_back(mp[v]);
            deg[mp[v]] += 1;
        }
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(deg[k]==0)
                {
                    ans.push_back(k);
                    deg[k]= -1;
                    for(int l=0;l<node[k].size();l++)
                    {
                        int a=node[k][l];
                        deg[a] -=1;
                    }
                    break;
                }
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",i++);
        for(j=0;j<ans.size();j++)
        {
            cout<<al[ans[j]];
            if(j==ans.size()-1)
                printf(".\n\n");
            else printf(" ");
        }
        for(j=1;j<=n;j++)
        {
            deg[j]=0;
            node[j].clear();
        }
        mp.clear();
        al.clear();
        ans.clear();
    }
    return 0;
}
