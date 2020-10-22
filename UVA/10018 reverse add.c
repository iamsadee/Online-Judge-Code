#include<stdio.h>
int main()

{
    int N , p , i , rev , c[1000] , j ;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        rev=0;
        scanf("%d",&p);
        j=1 ;
        while(p!=0)
        {
            rev *= 10;
            c[j] = p%10 ;
            rev += c[j];
            p = p/10 ;
            j++;
        }
        printf("%d",rev);
    }
}
