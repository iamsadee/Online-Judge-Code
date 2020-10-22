#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,x,y;
    char ch[20];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",ch);
        x=strlen(ch);
        if(x==3)
        {
            if(ch[0]=='o' || ch[0]!='o')
            {
                if(ch[1]=='n' && ch[2]=='e')
                    printf("1\n");
            }
            if(ch[1]!='n')
            {
                if(ch[0]=='o' && ch[2]=='e')
                    printf("1\n");
            }
            if(ch[2]!='e')
            {
                if(ch[0]=='o' && ch[1]=='n')
                    printf("1\n");
            }
            if(ch[0]=='t' || ch[0]!='t')
            {
                if(ch[1]=='w' && ch[2]=='o')
                    printf("2\n");
            }
            if(ch[1]!='w')
            {
                if(ch[0]=='t' && ch[2]=='o')
                    printf("2\n");
            }
            if(ch[2]!='o')
            {
                if(ch[0]=='t' && ch[1]=='w')
                    printf("2\n");
            }

        }
        else if(x==5)
        {
            printf("3\n");
        }
    }
    return 0;
}
