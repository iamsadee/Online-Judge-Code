#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,arr[21];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+n);
        int x=(arr[n-1]-arr[0])*2;
        printf("%d\n",x);
    }
    return 0;
}
