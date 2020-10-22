#include<stdio.h>
int main()

{
    int n , k , a,c , d ;
    while(scanf("%d %d",&n,&k)==2)
    {
        a = n;
        while(n>=k)
        {
            c = n/k ;
            d = n%k ;
            a += c ;
            n= d+c ;

        }
        printf("%d\n",a);
    }
    return 0;
}
