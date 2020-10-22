#include<stdio.h>
int main()
{
    long long int n , T , i , j ,k,sum;
    char ch[1000];
    scanf("%lld",&T);
    getchar();
    sum=0;
    for(i=1;i<=T;i++)
    {
        scanf("%s",ch);
        if(!(strcmp(ch,"donate")))
        {
            scanf("%lld",&k);
            sum += k;
        }
        else if(!(strcmp(ch,"report")))
        {
            printf("%lld\n",sum);
        }
    }
    return 0;
}
