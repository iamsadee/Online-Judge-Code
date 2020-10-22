#include<stdio.h>
int main()
{
    long long int b , s ,i=1;
    while(scanf("%lld %lld",&b,&s)==2)
    {
        if(b==0 && s==0)
            break;
        if(b-1==0)
            printf("Case %lld: :-\\\n",i);
        else if(s>=b)
            printf("Case %lld: :-|\n",i);
        else if(b>s)
            printf("Case %lld: :-(\n",i);
        i++;
    }
    return 0;
}
