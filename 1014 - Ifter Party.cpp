#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll p,l;
        scanf("%lld %lld",&p,&l);
        ll x=p-l;
        ll y=sqrt(x);
        vector<ll> ans;
        for(int j=1;j<=y;j++)
        {
            if(x%j==0)
            {
                if(j>l)
                {
                    ans.push_back((ll)j);
                }
                ll z=(x/j);
                if(x%z==0 && z!=j)
                {
                    if(z>l) ans.push_back(z);
                }
            }
        }
        if(ans.size()==0)
            printf("Case %d: impossible\n",i);
        else
        {
            sort(ans.begin(),ans.end());
            printf("Case %d: ",i);
            for(int j=0;j<ans.size();j++)
            {
                printf("%lld",ans[j]);
                if(j==ans.size()-1)
                    printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
