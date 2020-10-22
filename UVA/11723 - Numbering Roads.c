#include<stdio.h>
int main()

{
    int R , N , i=1 , x ;
    while(scanf("%d %d",&R,&N)==2)
    {
        if(R==0 && N==0)
            break;
        x = R/N ;

        if(R%N==0 && x-1 <= 26)
            printf("Case %d: %d\n",i,x-1);
        else if(x<=26)
            printf("Case %d: %d\n",i,x);
        else
            printf("Case %d: impossible\n",i);
        i++;
    }
    return 0;
}
