#include<stdio.h>
#include<math.h>

int main()

{
    int N ,  y , z , a ,c;
    float x ;

    while(scanf("%d",&N)==1)
    {

        y=1;
        z=0;
        if(N==0)
            break;
            while(z!=N)
            {
            a = N + (y*y*y) ;
            x =  pow(a,1.0/3);
            c = x ;
            z = ( c*c*c ) - (y*y*y) ;
            if(z==N)
            {
                printf("%d %d\n",c,y);
            }
            else
            {
                y++;
            }
            if(z>N)
                printf("No solution\n");
            if(z>N)
                break;
            }
    }
    return 0;
}
