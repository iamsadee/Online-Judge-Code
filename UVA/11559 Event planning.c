#include<stdio.h>

int main()

{

    int N , B , H , W , p[36] , a , i , j ,k,c, sum[1000] ,mx, l, money[1000],I,J,n;
    while(scanf("%d %d %d %d",&N,&B,&H,&W)==4)
    {
        l=1 ;


        c=1;
        for(i=1;i<=H;i++)
        {

            k=0;
            scanf("%d",&p[i]);
            for(j=1;j<=W;j++)
            {
                scanf("%d",&a);
                if(a>=0)
                {
                    k++;
                }



            }
            if(k==W)
            {
                sum[l] = N*p[i] ;
                l++;
            }

        }
        for(n=1;n<=l-1;n++)
        {
            if(sum[n]<=B)
            {
                money[c] = sum[n];
                c++;
            }
        }
        mx=0 ;
        for(I=1;I<=c-1;I++)
        {
            if(mx<=money[I])
            {
                mx = money[I] ;
            }
        }

        for(J=1;J<=c-1;J++)
        {
            if(mx>=money[J])
            {
                mx = money[J] ;
            }
        }

        if(mx==0)
            printf("stay home\n");
       else if(k==W)
        printf("%d\n",mx);
       else printf("stay home\n");


    }
    return 0;


}
