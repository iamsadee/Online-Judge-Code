#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll n,arr[105];
        scanf("%lld",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        int cnt=0;
        int j,k;
        for(j=1;j<=n;j++)
        {
            int temp=j,x=arr[j];
            int mn=1200;
            for(k=j+1;k<=n;k++)
            {
                if(x>arr[k])
                {
                    if(mn>arr[k])
                    {
                        mn=arr[k];
                        temp=k;
                    }
                }
            }
            if(temp!=j)
            {
                cnt++;
                swap(arr[j],arr[temp]);
            }
        }
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}


