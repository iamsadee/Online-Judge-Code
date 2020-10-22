#include<stdio.h>
int main()

{
    int T , i , d1 , d2 , m1 , m2 , y1 , y2 , year , month , day ;

    scanf("%d",&T);

        for(i=1;i<=T;i++)
        {

            scanf("%d/%d/%d",&d1,&m1,&y1);
            scanf("%d/%d/%d",&d2,&m2,&y2);
            day = d1 - d2 ;
            if(day<0)
            {
                day = day + 30 ;
                m1--;
            }
            month = m1-m2 ;
            if(month<0)
            {
                month = month + 12 ;
                y1-- ;
            }
            year = y1-y2 ;


                if(year <0)
                printf("Case #%d: Invalid birth date\n",i);
                else if(year > 130)
                printf("Case #%d: Check birth date\n",i);
                else printf("Case #%d: %d\n",i,year);

        }
        return 0;

}
