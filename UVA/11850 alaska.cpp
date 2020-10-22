#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , i , j , arr[2000];
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        arr[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        arr[n+1]=1422;
        sort(arr,arr+(n+1));
        j=0;
        for(i=0;i<=n;i++)
        {
            if(abs(arr[i]-arr[i+1])>200)
               {
                   j=1;
                   break;
               }
        }
        if(j==0)
        {
            if((abs(arr[n+1]-arr[n])*2)>200)
               {
                   j=1;
               }
        }
        if(j==0)
            printf("POSSIBLE\n");
        else if(j==1)
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
