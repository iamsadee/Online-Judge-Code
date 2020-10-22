#include<stdio.h>
int main()
{
    static char ch[101],str[150001][10000];
    long long int sum,i , j , k , n , m ,t,arr[101],l,o,K,count;
    double ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        sum = 0;
        scanf("%lld\n",&K);
        for(j=0;j<K;j++)
        {
            scanf("%c ",&ch[j]);
            scanf("%lld\n",&arr[j]);
        }
        scanf("%lld\n",&m);
        for(j=0;j<m;j++)
        {
            gets(str[j]);
        }
        for(j=0;j<K;j++)
        {
            count =0;
            for(k=0;k<m;k++)
            {
                for(l=0;str[k][l]!='\0';l++)
                {
                    if(str[k][l]==ch[j])
                    {
                        count++;
                    }
                }
            }
            sum +=(count*arr[j]);
        }
        ans = sum/100.0;
        printf("%0.2lf$\n",ans);
    }
    return 0;
}
