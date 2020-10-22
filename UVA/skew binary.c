#include<stdio.h>
#include<string.h>
int main()
{
    char str[100000];
    int x , y , i ;
    double ans;
    while(gets(str))
    {
        ans =0;
        if(strcmp(str,"0")==0)
            break;
        x = strlen(str);
        y=x;
        for(i=0;i<x;i++)
        {
            ans += ((str[i] - '0') *(pow(2,y) -1)) ;
            y--;
        }
        printf("%0.0lf\n",ans);
    }
}
