#include<stdio.h>
int main()
{
    int a, b , c , d , e , f ,g ;
    {
        while(scanf("%d %d %d",&a,&b,&c)==3)
        {
            if( a== 0 && b==0 && c==0)
                break ;
            if(a>b)
            {
                if(a>c) {f=a , e=b, d=c ;}
                else {f=c , e=a , d=b ;}
            }
            else
            {
                if(b>c) {f=b , e=a , d=c ; }
                else {f=c , e=a , d=b ;}
            }

            if(d*d + e*e == f*f) printf("right\n");
            else printf("wrong\n");


        }
    }
    return 0;
}
