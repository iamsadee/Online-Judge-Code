#include<stdio.h>
int main()
{
   char ch[101];
   int i , T , j ,count ;
   scanf("%d",&T);
   getchar();
   for(i=1;i<=T;i++)
   {
       count = 0;
       gets(ch);
       for(j=0;ch[j]!='\0';j++)
       {
           if(ch[j]=='a')
           {
               count += 1 ;
           }
           else if(ch[j]=='b')
           {
               count += 2 ;
           }
           else if(ch[j]=='c')
           {
               count += 3 ;
           }
           else if(ch[j]=='d')
           {
               count += 1 ;
           }
           else if(ch[j]=='e')
           {
               count += 2 ;
           }
           else if(ch[j]=='f')
           {
               count += 3 ;
           }
           else if(ch[j]=='g')
           {
               count += 1 ;
           }
           else if(ch[j]=='h')
           {
               count += 2 ;
           }
           else if(ch[j]=='i')
           {
               count += 3 ;
           }
           else if(ch[j]=='j')
           {
               count += 1 ;
           }
           else if(ch[j]=='k')
           {
               count += 2 ;
           }
           else if(ch[j]=='l')
           {
               count += 3 ;
           }
           else if(ch[j]=='m')
           {
               count += 1 ;
           }
           else if(ch[j]=='n')
           {
               count += 2 ;
           }
           else if(ch[j]=='o')
           {
               count += 3 ;
           }
           else if(ch[j]=='p')
           {
               count += 1 ;
           }
           else if(ch[j]=='q')
           {
               count += 2 ;
           }
           else if(ch[j]=='r')
           {
               count += 3 ;
           }
           else if(ch[j]=='s')
           {
               count += 4 ;
           }
           else if(ch[j]=='t')
           {
               count += 1 ;
           }
           else if(ch[j]=='u')
           {
               count += 2 ;
           }
           else if(ch[j]=='v')
           {
               count += 3 ;
           }
           else if(ch[j]=='w')
           {
               count += 1 ;
           }
           else if(ch[j]=='x')
           {
               count += 2 ;
           }
           else if(ch[j]=='y')
           {
               count += 3 ;
           }
           else if(ch[j]=='z')
           {
               count += 4 ;
           }
           else if(ch[j]==' ')
           {
               count += 1 ;
           }
       }
       printf("Case #%d: %d\n",i,count);
   }
   return 0;
}
