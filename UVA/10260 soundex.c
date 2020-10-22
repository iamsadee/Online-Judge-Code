#include<stdio.h>
int main()
{
    char ch[31] , str[100];
    int i,j ;
    while(gets(ch))
    {
        j=0;
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]=='B' || ch[i]=='F' || ch[i]=='P' || ch[i]=='V')
            {
                str[j]='1';
                j++;
                if(j>0)
                {

                   if(ch[i-1]=='B' || ch[i-1]=='F' || ch[i-1]=='P' || ch[i-1]=='V')
                   {
                       j--;
                   }
                }
            }
            else if(ch[i]=='C' ||ch[i]=='Q'|| ch[i]=='G' || ch[i]=='J' || ch[i]=='K' || ch[i]=='S' ||ch[i]=='X' || ch[i]=='Z' )
            {
                str[j]='2';
                j++;
                if(j>0)
                {

                    if(ch[i-1]=='C' || ch[i-1]=='Q'||ch[i-1]=='G' || ch[i-1]=='J' || ch[i-1]=='K' || ch[i-1]=='S' || ch[i-1]=='X' || ch[i-1]=='Z')
                  {
                     j--;
                  }
                }
            }
            else if(ch[i]=='D' || ch[i]=='T')
            {
                str[j]='3';
                j++;
                if(j>0)
                {
                    if(ch[i-1]=='D' || ch[i-1]=='T')
                        {
                            j--;
                        }
                }
            }
            else if(ch[i]=='L')
            {
                str[j]='4';
                j++;
                if(j>0)
                {
                    if(ch[i-1]=='L' )
                        {
                            j--;
                        }
                }
            }
            else if(ch[i]=='M' || ch[i]=='N')
            {
                str[j]='5';
                j++;
                if(j>0)
                {
                    if(ch[i-1]=='M' || ch[i-1]=='N')
                        {
                            j--;
                        }
                }
            }
            else if(ch[i]=='R')
            {
                str[j]='6';
                j++;
                if(j>0)
                {
                    if(ch[i-1]=='R' )
                        {
                            j--;
                        }
                }
            }
        }
        str[j]='\0';
        printf("%s\n",str);
    }
    return 0;
}
