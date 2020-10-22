#include<stdio.h>
int main()
{
    long long int n ,t,i,j,x,y,temp,z;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        x=4;
        temp=4;
        y=2*temp;
        for(j=3;j<=n;j++)
        {
            x=x;
            temp=temp;
            y=2*temp;
            z=x+y;
            temp=y;
            x=z;
        }
        if(n==1)
            printf("1\n");
        else if(n==2)
            printf("4\n");
        else printf("%lld\n",z);
    }
    return 0;
}

