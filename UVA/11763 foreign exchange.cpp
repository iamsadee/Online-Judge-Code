#include<bits/stdc++.h>
using namespace std;
int main()
{
    static long long int arr[500001],ar[500001],n,i,count;
    while(scanf("%lld",&n)==1)
    {
        count=0;
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            scanf("%lld",&ar[i]);
        }
        sort(arr,arr+n);
        sort(ar,ar+n);
        for(i=0;i<n;i++)
        {
            if(arr[i]==ar[i])
                count++;
        }
        if(count==n)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
