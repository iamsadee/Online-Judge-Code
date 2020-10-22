
#include<stdio.h>
#include<string.h>
int main()
{
    char ch[102],str[102];
    int x,n , i , j ,y,z,k;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        getchar();
        gets(ch);
        x=strlen(ch);
        y= x/n;
        z=0;
        k=0;
        for(i=1;i<=n;i++)
        {
           for(j=y-1;j>=z;j--)
           {
               str[k]=ch[j];
               k++;
           }
           y+=(x/n);
           z+=(x/n);
        }
        str[k]='\0';
        printf("%s\n",str);
    }
    return 0;
}
