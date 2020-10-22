#include<stdio.h>
long long int digit(long long int n)
{
    long long int sum=0 ,x ;
    while(n!=0)
    {
        sum += n%10 ;
        n = n/10 ;
    }
    return sum ;
}
int main()
{
    char ch[1001];
    long long int i , j , k , sum;
    while(gets(ch))
    {
        if(ch[0]=='0'&& strlen(ch)==1)
            break;
        sum =0;
        for(i=0;ch[i]!='\0';i++)
        {
            sum += ch[i]-'0' ;
        }
        k=1 ;
        j=sum ;
        while(sum>10)
        {
            sum = digit(sum);
            k++;
        }
        if(j%9==0)
        {
            printf("%s is a multiple of 9 and has 9-degree %lld.\n",ch,k);
        }
        else printf("%s is not a multiple of 9.\n",ch);
    }
    return 0;
}
