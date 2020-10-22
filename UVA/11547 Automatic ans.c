#include<stdio.h>

int main()

{
    int t ,  n , c , i , j,rem ;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        c = ((((((n*567)/9)+7492)*235)/47)-498) ;
        for(j=1;j<=1;j++)
        {
            c = c/10 ;
            rem = c%10 ;
            if(rem<0)
            {
                rem =  rem * (-1) ;
            }


        }
        printf("%d\n",rem);
    }
    return 0;
}
