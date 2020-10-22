#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,m;
    while(scanf("%d %d",&m,&n)==2)
    {
        if(n==0 && m==0)
        {
            break;
        }
        int i,j;
        vector< pair<int,int> > team,table;
        int a;
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            team.push_back(make_pair(a,i+1));
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            table.push_back(make_pair(a,i+1));
        }
        sort(table.begin(),table.end());
        sort(team.begin(),team.end());
        int chk=0;
        vector<int> ans[75];
        for(i=team.size()-1;i>=0;i--)
        {
            int x=0;
            for(j=0;j<n;j++)
            {
                if(table[j].first>0 && x<team[i].first)
                {
                    x++;
                    table[j].first -=1;
                    ans[team[i].second].push_back(table[j].second);
                }
                if(x==team[i].first)
                {
                    break;
                }
            }
            if(x<team[i].first)
            {
                chk=1;
                break;
            }
        }
        if(chk==0)
        {
            printf("1\n");
            for(i=1;i<=m;i++)
            {
                sort(ans[i].begin(),ans[i].end());
                for(j=0;j<ans[i].size();j++)
                {
                    printf("%d",ans[i][j]);
                    if(j==(ans[i].size()-1))
                        printf("\n");
                    else printf(" ");
                }
            }
        }
        else printf("0\n");
    }
    return 0;
}
