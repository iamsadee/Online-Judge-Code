#include<stdio.h>
int main()
{
    char ch[31];
    int i ;
    while(gets(ch))
    {
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]>='A' && ch[i]<='C' )
            {
                ch[i] = '2' ;
            }
            if(ch[i]>='D' && ch[i]<='F' )
            {
                ch[i] = '3' ;
            }
            if(ch[i]>='G' && ch[i]<='I' )
            {
                ch[i] = '4' ;
            }
            if(ch[i]>='J' && ch[i]<='L' )
            {
                ch[i] = '5' ;
            }
            if(ch[i]>='M' && ch[i]<='O' )
            {
                ch[i] = '6' ;
            }
            if(ch[i]>='P' && ch[i]<='S' )
            {
                ch[i] = '7' ;
            }
            if(ch[i]>='T' && ch[i]<='V' )
            {
                ch[i] = '8' ;
            }
            if(ch[i]>='W' && ch[i]<='Z' )
            {
                ch[i] = '9' ;
            }
        }
        printf("%s\n",ch);
    }
    return 0;
}
