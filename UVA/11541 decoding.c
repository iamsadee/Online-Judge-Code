#include<stdio.h>
int main()
{
    char ch[300] , str[300];
    int t , i , j ,k ,a ,b , c ,sum,x;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        gets(ch);
        sum = 0;
        for(j=0;ch[j]!='\0';j++)
        {
            if(ch[j]>='A' && ch[j]<='Z')
            {
                k = j+1;
                a=j+1 ;
                while(ch[k]>='0' && ch[k]<='9')
                {
                    k++;
                }
                b = k-a ;
                x= sum ;
                if(b==3)
                {
                    sum += (ch[k-1]-'0')*1 + (ch[k-2]-'0')*10 + (ch[k-3]-'0')*100 ;
                }
                else if(b==2)
                {
                    sum += (ch[k-1]-'0')*1 + (ch[k-2]-'0')*10  ;
                }
                else if(b==1)
                {
                    sum += (ch[k-1]-'0')*1   ;
                }
                for(c=x;c<sum;c++)
                {
                    str[c]=ch[j];
                }
             }
        }
        str[sum]='\0';
        printf("Case %d: %s\n",i,str);
    }
    return 0;
}
