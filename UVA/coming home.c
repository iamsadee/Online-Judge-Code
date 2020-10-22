#include<stdio.h>
int main()


{
    int T , i , j , k , m , h,mm,hh,M,H,t ,x,mx,y , z;
    char ch;

    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        mx = 2441 ;
        scanf("%d%d%c%d",&k,&y,&ch,&z);
        for(j=1;j<=k;j++)
        {
            h = y ;
            m = z;

            scanf("%d%c%d%d",&hh,&ch,&mm,&t);
            if(m>mm)
            {
                M = mm - m + 60 ;
                h +=1 ;
            }
            else if(mm>=m)
            {
                M = mm -m ;
            }
            if(h>hh)
            {
                H = hh - h + 24;
            }
            else if(hh>=h)
            {
                H = hh - h ;
            }
            x = 60*H + M + t ;
            if(mx>=x)
            {
                mx = x;
            }

        }
        printf("Case %d: %d\n",i,mx);


    }
    return 0;
}

