#include<stdio.h>
#include<string.h>
int main()
{
    static char ch[101][101],str[101][101],arr[200];
    int i ,j, sum=0,a,b,mx=0 ,k,x,c;
    for(i=0;;i++)
    {
        gets(ch[i]);
        if(strcmp(ch[i],"0")==0)
            break;
    }
    for(j=0;j<i;j++)
    {
        a=strlen(ch[j]);
        if(mx<=a)
        {
            mx = a;
        }
    }
    for(j=0;j<i;j++)
    {
        a=strlen(ch[j]);
        b=mx-a;
        for(k=0;k<b;k++)
        {
            str[j][k]='0';
        }
        strcat(str[j],ch[j]);
    }
    for(j=mx-1;j>=0;j--)
    {
        for(k=0;k<i;k++)
        {
            sum += (ch[k][j]-'0') ;
        }
        if(j==0)
        {
            if(sum>=10)
            {
                i=1;
                c=sum/10;
            }
        }
        if(sum<10)
        {
            arr[j] = sum + '0';
            sum =0;
        }
        else if(sum>=10)
        {
            arr[j] = (sum%10)+'0';
            sum=sum/10 ;
        }
    }
    arr[mx] = '\0';
    if(i==1)
    {
        printf("%d%s\n",c,arr);
    }
    else printf("%s\n",arr);
    return 0;
}
