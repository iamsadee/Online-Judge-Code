#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j,k;
    long long x,arr[100005],m[100005];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        x=-10000000000000;
        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
            x=max(x,arr[j]);
            m[j] = x;
        }
        x=-100000000000;
        for(j=n-1;j>=1;j--)
        {
            x=max(x,m[j-1]-arr[j]);
        }
        printf("%lld\n",x);
    }
    return 0;
}
