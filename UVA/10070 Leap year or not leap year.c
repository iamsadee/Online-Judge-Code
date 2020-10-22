#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100000];
    long long int i,j=0,k,x,y,z,a,b,c,v;
    while(scanf("%s",ch)==1)
    {
        if(j!=0)
            printf("\n");
        a=0;
        b=0;
        c=0;
        y=0;
        z=0;
        v=0;
        x=strlen(ch);
        for(i=0;i<x;i++)
        {
            a = (a*10+(ch[i]-'0'));
            b= (b*10+(ch[i]-'0'));
            c = (c*10+(ch[i]-'0'));
            z= (z*10+(ch[i]-'0'));
            v = (v*10+(ch[i]-'0'));
            a=a%4;
            b=b%15;
            c=c%55;
            z=z%100;
            v=v%400;
        }
        if(a==0 &&(v==0 || z!=0))
            {
                y=1;
                printf("This is leap year.\n");
            }
        if(b==0)
        {
            y=1;
            printf("This is huluculu festival year.\n");
        }
        if((a==0 &&(v==0 || z!=0)) && c==0)
            {
                y=1;
                printf("This is bulukulu festival year.\n");
            }
        if(y!=1 )
            printf("This is an ordinary year.\n");
        j=1;
    }
    return 0;
}
