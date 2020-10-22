#include<bits/stdc++.h>

using namespace std;
int main()
{
    static int arr[2000000];
    long long int n , i ;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;


    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);

    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
        if(i==(n-1))
            printf("\n");
        else printf(" ");
    }
    }
    return 0;
}
