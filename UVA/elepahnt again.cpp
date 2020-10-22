#include<bits/stdc++.h>
using namespace std;

int main()


{
    int t , M , W , weight[100000] , i , j , k , sum ,temp , a , b ,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&M,&W);
        sum = 0 ;
        k=0;
        for(j=0;j<M;j++)
        {
            scanf("%d",&weight[j]);

        }
        sort(weight,weight+M);

        for(a=0;a<M;a++)
        {
            sum += weight[a];
                if(sum<=W)
                {
                    k++;
                }
        }
        printf("%d\n",k);

   }

    return 0;
}


