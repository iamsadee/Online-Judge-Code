#include<stdio.h>
int main()

{
    int S , i , j , num[14] ,b,c;

    scanf("%d",&S);
    b=0;
    for(i=S;i>=1;i--)
    {
        b++ ;
        c = 0 ;
        for(j=1;j<=13;j++)
        {
            scanf("%d",&num[j]);
            if(num[j]>128 || num[j]==0)
            {
                c++ ;
            }
        }
        if(c>0)
            printf("Set #%d: No\n",b);
        else if(c==0)
        {
            printf("Set #%d: Yes\n",b);
        }

    }


    return 0;
}
