#include<stdio.h>
int main()

{
    int T , a , b , c , d , e , f , g , i ,h ,j ,k ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g);
        if(e>=f)
        {
            if(e>=g)
                h=e ;
            else h=g ;
        }
        else
        {
            if(f>=g)
                h=f ;
            else h = g ;
        }

        if(e>=f && e<=g)
            j = e ;
        else if(f>=g && f<=e)
            j = f ;
        else if(g>=e && g<=f)
            j = g ;
        else if(e<=f && e>=g)
            j = e ;
        else if(f<=g && f>=e)
            j = f ;
        else if(g<=e && g>=f)
            j = g ;

        k = (a+b+c+d)+((h+j)/2) ;
        if(k<=100 && k>=90)
            printf("Case %d: A\n",i);
        if(k<90 && k>=80)
            printf("Case %d: B\n",i);
        if(k<80 && k>=70)
            printf("Case %d: C\n",i);
        if(k<70 && k>=60)
            printf("Case %d: D\n",i);
        if(k<60)
            printf("Case %d: F\n",i);

    }
    return 0;
}
