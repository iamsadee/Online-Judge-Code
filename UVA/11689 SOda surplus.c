#include<stdio.h>
int main()

{
    int N , e , f , c , i ,a, b ,d  ;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        int j =0;
        scanf("%d %d %d",&e,&f,&c);
        a = e+f;
        while(a>=c)
        {
            b = a/c ;
            d = a%c ;
            j = j+b ;
            a = b+d ;

        }
        printf("%d\n",j);
    }
    return 0;

}
