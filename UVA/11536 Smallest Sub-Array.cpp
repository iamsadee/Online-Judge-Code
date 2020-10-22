
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    int i,j;
    for(i=1;i<=t; i++)
    {
        ll n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);
        static ll arr[1000005];
        ll x;
        arr[0]=1;
        arr[1]=2;
        arr[2]=3;
        for(j=3; j<n; j++)
        {
            x= (arr[j-1]+arr[j-2]+arr[j-3])%m + 1;
            arr[j]=x;
        }
        static ll mp[1000005];
        memset(mp,0,sizeof mp);
        ll l=0,r=0;
        ll cnt=0;
        ll mn = 100000005;
        while(r<n)
        {
            if(cnt<k)
            {
                if(mp[arr[r]]==0 && arr[r]<=k)
                {
                    cnt++;
                    if(cnt==k)
                    {
                        mp[arr[r]] += 1;
                    }
                }
                if(cnt<k)
                {
                    mp[arr[r]] += 1;
                    r++;
                }
            }
            if(cnt==k)
            {
                mp[arr[l]] -=1;
                mn=min(mn,r-l+1);
                if(mp[arr[l]] ==0 && arr[l]<=k)
                {
                    cnt -=1;
                    r++;
                }
                l++;
            }
        }
        if(mn==100000005)
        {
            printf("Case %d: sequence nai\n",i);
        }
        else printf("Case %d: %lld\n",i,mn);
    }
    return 0;
}
