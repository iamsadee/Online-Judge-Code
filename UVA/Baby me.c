#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    int i,T,a,j,b,k,x,y,z;
    double ans;
    scanf("%d",&T);
    getchar();
    for(i=1;i<=T;i++)
    {
        gets(str);
        a = strlen(str);
        z=0;
        ans=0;
        for(j=0;j<a;j++)
        {
            if(str[j] =='斤')
            {
                b=j-2;
                x=0;
                y=1;
                for(k=b;k>=0;k--)
                {
                    x += (str[k]-'0' * y);
                    y = y*10;
                }
                if(z%2==0)
                {
                    ans += x* 0.5 ;
                    z++;
                }
                else if(z%2==1)
                {
                    ans += x* 0.05 ;
                    z++;
                }
            }
        }
        printf("%0.2lf\n",ans,z);
    }
    return 0;
}
