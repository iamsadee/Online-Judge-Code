#include<bits/stdc++.h>
using namespace std;

int main()

{
    int N , arr[10001] , M ,i,j,sum;

    while(scanf("%d",&N)==1)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        scanf("%d",&M);

        sort(arr,arr+N);


        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                sum = arr[i] + arr[j];
                if(sum == M && arr[i] <= arr[j])
                    break;
            }
            if(sum == M && arr[i] <= arr[j])
                    break;
        }
        printf("\nPeter should buy books whose prices are %d and %d.\n",arr[i],arr[j]);
    }
    return 0;

}
