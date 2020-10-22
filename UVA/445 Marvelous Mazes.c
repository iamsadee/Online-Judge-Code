#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100000];
    int i,j,k,x,y,z;
    while(gets(ch))
    {
        x=strlen(ch);
        y=0;
        for(i=0;i<x;i++)
        {
            z=ch[i]-'0';
            if(z >=1 && z<=9)
            {
                y+=z;
            }
            if((ch[i]>='A' && ch[i]<='Z') || ch[i]=='b' || ch[i]=='*' )
            {
                if(y==0)
                {
                    y=1;
                }
                for(j=0;j<y;j++)
                {
                    if(ch[i]=='b')
                        printf(" ");
                    else if(ch[i]=='*')
                        printf("*");
                    else printf("%c",ch[i]);
                }
                y=0;
            }
            if(ch[i]=='!')
                printf("\n");
        }
        printf("\n");
    }
    return 0;
}
