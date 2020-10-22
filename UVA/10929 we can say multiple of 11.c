#include<stdio.h>
#include<string.h>
int main()
{
    char ch[10001],str[1001];
    long long int i , j,a,sum ;
    while(gets(ch))
    {
        if(ch[0]=='0' && strlen(ch)==1)
            break;
        sum =0 ;
        i=0;
        for(j=0;ch[j]!='\0';j++)
        {
            if(ch[j]>='0' && ch[j]<='9')
            {
                str[i]=ch[j];
                i++;
            }
        }
        str[i] = '\0';
        a = strlen(str);
        for(i=a-1;i>=0;i--)
        {
            if(a%2==0)
            {
                if(i%2==0)
                {
                    sum += (str[i]-'0')*10 ;
                }
                else if(i%2==1)
                {
                    sum += (str[i]-'0')*1 ;
                }
            }
            else if(a%2==1)
            {
                if(i%2==0)
                {
                    sum += (str[i]-'0')*1 ;
                }
                else if(i%2==1)
                {
                    sum += (str[i]-'0')*10 ;
                }
            }
        }
        if(sum%11==0)
        {
            printf("%s is a multiple of 11.\n",str);
        }
        else printf("%s is not a multiple of 11.\n",str);
    }
    return 0;
}
