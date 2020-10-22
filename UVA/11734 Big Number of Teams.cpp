#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch[21],ar[21],x[21],y[21];
    int t,i,j,a,b,k;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        scanf("%[^\n]",ch);
        getchar();
        scanf("%[^\n]",ar);
        getchar();
        if(strcmp(ch,ar)==0)
        {
            printf("Case %d: Yes\n",i);
        }
        else
        {
            a=strlen(ch);
            b=strlen(ar);
            k=0;
            for(j=0;j<a;j++)
            {
                if(ch[j]!=' ')
                {
                    x[k++]=ch[j];
                }
            }
            x[k]='\0';
            k=0;
            for(j=0;j<b;j++)
            {
                if(ar[j]!=' ')
                {
                    y[k++]=ar[j];
                }
            }
            y[k]='\0';
            if(strcmp(x,y)==0)
                printf("Case %d: Output Format Error\n",i);
            else printf("Case %d: Wrong Answer\n",i);
        }
    }
    return 0;
}
