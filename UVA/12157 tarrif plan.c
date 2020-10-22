#include<stdio.h>

int main()

{
    int T , N ,i , j ,k, dur[21] , c ,  b, mil[21] , juc[21] , x ,y  ;
    double  f , g ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        for(j=1;j<=N;j++)
        {
            scanf("%d",&dur[j]);
            f = dur[j]/30.0 ;
            c=dur[j]/30 ;
            if(f>c)
            {
                c++ ;
            }
            if(dur[j]%30==0)
            {
                c++;
            }
            mil[j] = 10*c ;

            g= dur[j]/60.0;
            b = dur[j]/60 ;
            if(g>b)
            {
                b++;
            }
            if(dur[j]%60==0)
            {
                b++;
            }
            juc[j] = b*15;
        }
        x=0 ;
        y=0 ;
        for(k=1;k<=N;k++)
        {
            x+=mil[k];
            y+=juc[k];
        }
        if(x<y)
            printf("Case %d: Mile %d\n",i,x);
        else if(x>y)
            printf("Case %d: Juice %d\n",i,y);
        else if(x==y)
            printf("Case %d: Mile Juice %d\n",i,x);

    }
    return 0;

}
