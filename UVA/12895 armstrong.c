#include<stdio.h>

int main()


{
    long long int T , N , i,j ,k,l, num[100] , rem,x ,a,c,m ;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld",&N);
        j=1;
        m=N;
        while(N!=0)
        {
            rem = N%10 ;
            num[j] = rem ;
            j++;
            N = N/10 ;
        }
        a=0 ;
        c= j-1;

        for(k=j-1;k>=1;k--)
        {
            x=1;
            for(l=1;l<=j-1;l++)
            {
                x = num[k]*x ;
            }
            a+=x;

        }
        if(a != m)
            {printf("Not Armstrong\n");}
        else if(a==m)
            {printf("Armstrong\n");}
    }
    return 0;
}
