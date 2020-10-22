#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        ll arr[105],ar[105];
        int n,j,k;
        cin>>n;
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&ar[j]);
        }
        sort(ar+1,ar+(n+1));
        sort(arr+1,arr+(n+1));
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            int k=1+i;
            for(int j=1;j<=n-i;j++)
            {
                if(arr[k]>ar[j])
                {
                    cnt +=2;
                }
                else if(arr[k]==ar[j])
                {
                    cnt++;
                }
                k++;
            }
            mx=max(mx,cnt);
        }
        printf("Case %d: %d\n",i,mx);
    }
    return 0;
}
