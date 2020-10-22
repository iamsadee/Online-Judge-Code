#include<stdio.h>
int main()

{
    int t , i,k=0 ;
    double l , w , d , we ;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %lf %lf %lf",&l,&w,&d,&we);

        if(((l<=56 && w <= 45 && d <= 25 ) || ((l+w+d )<= 125) ) && we<= 7)
        {
            printf("1\n");
            k++;
        }
        else printf("0\n");

    }
    printf("%d\n",k);
    return 0;

}
