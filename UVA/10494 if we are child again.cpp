#include<bits/stdc++.h>
using namespace std;
int main()
{
    char b,ch[100000],ans[100000];
    long long n,a,i,x,y;
    while(scanf("%s %c %lld",ch,&b,&a)==3)
    {
        if(b=='/')
        {
            x=strlen(ch);
            long long j=0,k=0;
            for(i=0;i<x;i++)
            {
                j = j*10 + (ch[i]-'0');
                if(j>=a)
                {
                    ans[k++]=(j/a+'0');
                    j=j%a;
                }
                else if(j==0)
                {
                    ans[k++]='0';
                }
                else if(j<a)
                {
                    ans[k++]='0';
                }
            }
            ans[k]='\0';
            i=0;
            x=strlen(ans);
            //printf("%lld %s ",x,ans);
            while(ans[i]=='0')
            {
                i++;
            }
            if(i==x)
            {
                printf("0");
            }
            else{
            for(j=i;j<x;j++)
            {
                printf("%c",ans[j]);
            }
            }
            printf("\n");
        }
        else if(b=='%')
        {
            x=strlen(ch);
            long long j=0,k=0;
            for(i=0;i<x;i++)
            {
                j = (j*10 + (ch[i]-'0'))%a;
            }
            printf("%lld\n",j);
        }
    }
    return 0;
}
