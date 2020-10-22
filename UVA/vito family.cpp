#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,k,t,arr[10000];
    long long sum,mx;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+n);
        sum=arr[0];
        j=n-1;
        k=1;
        mx=arr[j];
        while(sum!=mx && k<j)
        {
            sum+=arr[k];
            k++;
            if(sum>mx)
            {
                j--;
                mx+=arr[j];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
