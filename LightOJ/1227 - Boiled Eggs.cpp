#include<bits/stdc++.h>
using namespace std;

int main()

{
    int T , n , P , Q , arr[30], i , j , k , sum  ,m;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&n,&P,&Q);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+(n));
        sum = 0 ;
        m=0 ;
        for(k=0;k<n;k++)
        {
            sum+=arr[k];
            if(sum<=Q)
            {
                m++;
            }

        }
        if(m<P)
        {
            printf("Case %d: %d\n",i,m);
        }
        else if(m>=P)
        {
            printf("Case %d: %d\n",i,P);
        }





    }
    return 0;
}
