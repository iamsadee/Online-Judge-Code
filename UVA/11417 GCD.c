#include<stdio.h>
long long int gcd(long long int i , long long int j)
{
    long long int r,y=1;
    while(y!=0)
    {
        r = i%j ;
        i = j ;
        j = r;
        y=j;
    }
    return i;
}
int main()
{
    long long int i , n , j,G ;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        G=0;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                G+=gcd(i,j);
            }
        }
        printf("%lld\n",G);
    }
    return 0;
}
