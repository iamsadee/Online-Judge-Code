#include<stdio.h>
int main()

{
    int T , HH , MM ,i , hh , mm , h , m;
    char ch;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%c%d",&HH,&ch,&MM);
        hh = 12 ;
        mm = 00 ;
        m = mm-MM ;
        if(m<0)
        {
            m+=60 ;
            HH++;
        }
        h = hh - HH ;
        if(h<0)
        {
            h+=12;
        }


        if(h==0 & m==0)
        {
            printf("12:00\n");
        }


        else if(h<10 && m>=10 & h!=0)
        {
            printf("0%d:%d\n",h,m);
        }
        else if(h>=10 && m>=10 && h!=0)
        {
            printf("%d:%d\n",h,m);
        }
        else if(h<10 && m<10 && h!=0 )
        {
            printf("0%d:0%d\n",h,m);
        }
        else if(h>=10 && m<10 && h!=0)
        {
            printf("%d:0%d\n",h,m);
        }
        else if(h==0 && m<10)
        {
            printf("12:0%d\n",m);
        }
        else if(h==0 && m>=10)
        {
            printf("12:%d\n",m);
        }



    }
    return 0;
}
