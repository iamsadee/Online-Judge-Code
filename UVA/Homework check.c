#include<stdio.h>
int main()
{
    int a , b , sum , s ,x,count=0 ;
    char ch , A , str[10];
    while(scanf("%d%c%d%c%s",&a,&A,&b,&ch,str)==5)
    {
        if(A == '+')
        {
            sum = a+b ;
        }
        if(A=='-')
        {
            sum = a-b ;
        }
        s = strlen(str);
        if(str[0]!='?')
        {
            x = atoi(str) ;
        }
        if(sum==x)
        {
            count++ ;
        }
    }
    printf("%d\n",count);
    return 0;
}
