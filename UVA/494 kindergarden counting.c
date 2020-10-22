#include<stdio.h>
int main()
{
    char ch[100000];
    int i , count;
    while(gets(ch))
    {
        count=0;
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]>='A' && ch[i]<='z')
            {
                if(!(ch[i+1]>='A' && ch[i+1]<='z'))
                   count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
