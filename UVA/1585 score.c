#include<stdio.h>
int main()
{
    long long int n , T , i=0 , j ,k,sum;
    char ch[81];
    scanf("%lld",&T);
    getchar();
    for(j=1;j<=T;j++)
    {
        gets(ch);
        sum =0;
        k=0;
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]=='O')
            {
                k++;
                sum += k ;
            }
            else if(ch[i]=='X')
            {
                k=0;
                sum += k ;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
