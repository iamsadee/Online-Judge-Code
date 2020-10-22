#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100000];
    int i , j , k , l ,x,c ;
    while(gets(ch) && ch[0]!=EOF)
    {
        x=0 ;
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]==' ')
            {
                for(j=i-1;j>=x;j--)
                {
                    printf("%c",ch[j]);
                }
                x = i+1 ;
                printf(" ");
            }
        }
        for(j=i-1;j>=x;j--)
        {
            printf("%c",ch[j]);
        }
        printf("\n");
    }
    return 0;
}
