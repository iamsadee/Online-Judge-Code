#include<stdio.h>


int main()

{
    int a , b , m , n ;

    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==-1 && b==-1)
            break;
        if(a<b)
            {
                m = b-a ;
                n = (100-b+a) ;
              if(n<m)
                printf("%d\n",n);
               else printf("%d\n",m);
            }
        else if(a>=b)
        {
            m = a-b ;
            n = 100-a+b ;
            if(n<m)
                printf("%d\n",n);
            else printf("%d\n",m);
        }
    }
    return 0;
}
