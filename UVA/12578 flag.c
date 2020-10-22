#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()

{
    int T , L , i  ;
    double area , s , w , r  ;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&L);
        r = ((2/10.0)*L) ;
        area = PI*pow(r,2) ;
        w = ((6/10.0)*L) ;
        s = w*L ;

        printf("%0.2lf %0.2lf\n",area,s-area);
    }
 return 0;
}
