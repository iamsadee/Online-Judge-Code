#include<stdio.h>
int main()
{
    char ch[4][5] ;
    int i,j, x , sum , T , k , sum_1 , sum_2,y ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%s",ch[j]);
        }
        sum_1 = 0 ;
        sum_2 = 0 ;
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                x = ch[j][k] - '0' ;
                if(k%2==0)
                {
                    y = x*2 ;
                    sum_1 += (y/10 + y%10) ;
                }
                else
                {
                    sum_2 += x ;
                }
            }
        }
        sum = sum_1 + sum_2 ;
        if(sum%10==0)
        {
            printf("Valid\n");
        }
        else printf("Invalid\n");
    }
    return 0;
}
