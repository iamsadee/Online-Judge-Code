#include<stdio.h>
int main()
{
    int a , b , T , i  ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int sum = 0 ;
        scanf("%d%d",&a,&b);
        while( a!=b+1 )
        {
            if(a%2==1)
                sum += a ;
            a++ ;
        }


        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
