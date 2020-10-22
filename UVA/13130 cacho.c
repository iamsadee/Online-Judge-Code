#include<stdio.h>
int main()
{
    int t,i,a,b,c,d,e;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        if(b==a+1 && c==b+1 && d==c+1 && e==d+1)
            printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
