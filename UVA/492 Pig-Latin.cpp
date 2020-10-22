#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1000000];
    int i,j,x,y,k,l,a;
    while(scanf("%[^\n]",ch)==1)
    {
        getchar();
        x=strlen(ch);
        j=0;
        l=0;
        for(i=0;i<x;i++)
        {
            l=i;
            if((ch[i]>='a' && ch[i]<='z') ||(ch[i]>='A' && ch[i]<='Z'))
            {
                if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u' || ch[i]=='A'| ch[i]=='E' || ch[i]=='I' || ch[i]=='O' || ch[i]=='U')
                {
                    while(((ch[i]>='a' && ch[i]<='z') ||(ch[i]>='A' && ch[i]<='Z')))
                    {
                        i++;
                    }
                    for(;l<i;l++)
                    {
                        printf("%c",ch[l]);
                    }
                    printf("%c",'a');
                    printf("%c",'y');
                    printf("%c",ch[i]);
                }
                else
                {
                    while(((ch[i]>='a' && ch[i]<='z') ||(ch[i]>='A' && ch[i]<='Z')))
                    {
                        i++;
                    }
                    k=i-1;
                    for(k=l+1;k<i;k++)
                    {
                        printf("%c",ch[k]);
                    }
                    printf("%c",ch[l]);
                    printf("%c",'a');
                    printf("%c",'y');
                    printf("%c",ch[i]);
                }
            }
            else
            {
                printf("%c",ch[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
