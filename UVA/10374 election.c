#include<stdio.h>
#include<string.h>
int main()
{
    static char ch[41][81],str[10001][81] ;
    int arr[2001] , i , j , t , k,a,b,x,count,mx,n ;
    scanf("%d\n",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d\n",&a);
        x = 2*a ;
        for(j=0;j<x;j++)
        {
            gets(ch[j]);
        }
        scanf("%d\n",&b);
        for(j=0;j<b;j++)
        {
            gets(str[j]);
        }
        mx =0;
        for(j=0;j<x;j+=2)
        {
            count=0;
            for(k=0;k<b;k++)
            {
                if(!(strcmp(ch[j],str[k])))
                {
                    count++;
                }
            }
            if(mx<=count)
            {
                mx = count ;
            }
            arr[j] = count ;
        }
        count=0;
        for(j=0;j<x;j=j+2)
        {
            if(mx==arr[j])
            {
                count++;
                n=j;
            }
        }
        if(count>1)
            printf("tie\n");
        else printf("%s\n",ch[n+1]);
        if(i!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
