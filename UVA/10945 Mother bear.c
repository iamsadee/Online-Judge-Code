#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,x,y,k,count;
    char ch[100000],str[100000];
    while(gets(ch))
    {
        if(!(strcmp(ch,"DONE")))
           break;
        x=strlen(ch);
        j=0;
        for(i=0;i<x;i++)
        {
            if(ch[i]>='A' && ch[i]<='Z')
            {
                str[j]=(((ch[i]-'0')+32)+'0');
                j++;
            }
            else if(ch[i]>='a' && ch[i]<='z')
            {
                str[j]=ch[i];
                j++;
            }
        }
        str[j]='\0';
        count=0;
        for(i=0,k=j-1;i<j;i++,k--)
        {
            if(str[i]==str[k])
            {
                count++;
            }
        }
        if(count==j)
            printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}
