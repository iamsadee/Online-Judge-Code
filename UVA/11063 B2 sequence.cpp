#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    int i,j;
    ll arr[105];
    int k=1;
    while(scanf("%d",&n)==1)
    {
        int chk=0;
        arr[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i-1]>=arr[i])
            {
                chk=1;
            }
        }
        map<ll,bool> mp;
        for(i=1;i<=n;i++)
        {
            if(chk==1)
                break;
            for(j=1;j<=i;j++)
            {
                ll x=arr[i]+arr[j];
                if(mp[x]==0)
                {
                    mp[x]=1;
                }
                else if(mp[x]==1)
                {
                    chk=1;
                    break;
                }
            }
        }
        if(chk==1)
        {
            printf("Case #%d: It is not a B2-Sequence.\n\n",k++);
        }
        else printf("Case #%d: It is a B2-Sequence.\n\n",k++);

    }
    return 0;
}
