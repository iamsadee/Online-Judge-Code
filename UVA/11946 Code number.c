#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,x,y,t,z;
    char ch[101][82];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        k=1;
        while(gets(ch[k]))
        {
           x=strlen(ch[k]);
           if(x<1 )
                break;
           for(j=0;j<x;j++)
           {
               if(ch[k][j]=='1')
               {
                   ch[k][j]='I';
               }
               else if(ch[k][j]=='2')
               {
                   ch[k][j]='Z';
               }
               else if(ch[k][j]=='3')
               {
                   ch[k][j]='E';
               }
               else if(ch[k][j]=='4')
               {
                   ch[k][j]='A';
               }
               else if(ch[k][j]=='5')
               {
                   ch[k][j]='S';
               }
               else if(ch[k][j]=='6')
               {
                   ch[k][j]='G';
               }
               else if(ch[k][j]=='7')
               {
                  ch[k][j]='T';
               }
               else if(ch[k][j]=='8')
               {
                   ch[k][j]='B';
               }
               else if(ch[k][j]=='9')
               {
                   ch[k][j]='P';
               }
               else if(ch[k][j]=='0')
               {
                   ch[k][j]='O';
               }
           }
           if(k==100)
            break;
           k++;
        }
        for(z=1;z<k;z++)
        {
            printf("%s\n",ch[z]);
        }
        if(i!=t)
            printf("\n");
    }
    return 0;
}

