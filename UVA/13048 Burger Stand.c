#include<stdio.h>
#include<string.h>
int main()
{
    char ch[51];
    int i,j,k,x,y,z,t,chk;
    scanf("%d",&t);
    getchar();
    for(j=1;j<=t;j++)
    {
        gets(ch);
        x=strlen(ch);
        chk=0;
        for(i=0;i<x;i++)
        {
            z=0;
            if(ch[i]=='-')
            {
                if((i+2)<x )
                {
                    if(ch[i+2]=='B')
                         z=1;
                    if(ch[i+1]=='B' || ch[i+1]=='S')
                        z=1;
                }
                else if((i+1)<x)
                {
                    if(ch[i+1]=='B' || ch[i+1]=='S')
                        z=1;
                }
                if((i-1)<x)
                {
                    if(ch[i-1]=='S')
                        z=1;
                }
                if(z==0)
                    {
                        chk++;
                    }
            }
        }
        printf("Case %d: %d\n",j,chk);
    }
    return 0;
}
