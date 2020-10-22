#include<stdio.h>
#include<string.h>
int main()
{
    int i , j , k , m,n ,a;
    char str[40][10000],ch[10000];
    scanf("%d",&n);
    getchar();
    a=n*2;
    for(i=0;i<a;i++)
    {
        gets(str[i]);
    }
    scanf("%d",&m);
    getchar();
    for(j=0;j<m;j++)
    {
        gets(ch);
        for(k=0;k<a;k+=2)
        {
            if(strcmp(ch,str[k])==0)
            {
                printf("%s\n",str[k+1]);
            }
        }
    }
    return 0;
}
