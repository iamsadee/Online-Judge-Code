#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    int t,i,j,k,n,arr[1005];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        int sum=0;
        for(j=n-1;j>=1;j--)
        {
            for(k=j-1;k>=0;k--)
            {
                if(arr[k]<=arr[j])
                {
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
