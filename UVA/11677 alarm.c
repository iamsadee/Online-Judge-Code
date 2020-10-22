#include<stdio.h>

int main()

{
    int h1 , m1 , h2 , m2 , min , m , h ,n ;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2)==4)
    {
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break ;
        m = m2 - m1 ;
        if(m<0)
        {
            m+=60 ;
            h1++ ;
        }
        h = h2 - h1 ;
        if(h<0)
        {
            h += 24 ;
        }
        min = (h*60) + m ;
        printf("%d\n",min);
    }
    return 0;
}
