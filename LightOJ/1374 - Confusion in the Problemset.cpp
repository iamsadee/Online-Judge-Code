#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll arr[10005];
        int n;
        scanf("%d",&n);
        int cnt=0;
        map<int,int> mp;
        int chk=0;
        for(int i=1;i<=n;i++)
        {
            ll x;
            scanf("%lld",&x);
            mp[x] += 1;
        }
        for(int i=1;i<=n;i++)
        {
            if(mp[i-1]==0 && mp[n-i]==0)
            {
                cnt=1;
                break;
            }
            else if(mp[n-i]>0)
                mp[n-i]--;
            else if(mp[i-1]>0)
            {
                mp[i-1]--;
            }
        }
        if(cnt==0)
        {
            printf("Case %d: yes\n",a);
        }
        else
        {
            printf("Case %d: no\n",a);
        }
    }
    return 0;
}
