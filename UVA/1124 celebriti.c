#include <stdio.h>
#include<string.h>
int main()
{
    char ch[1000] ;
    while(gets(ch) && ch[0]!=EOF )
        printf("%s\n",ch);

    return 0;
}
