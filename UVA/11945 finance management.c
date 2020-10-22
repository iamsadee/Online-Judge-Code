#include<stdio.h>
int main()
{
    double arr[12] ,sum , avg,a;
    long long int i , t ,j,x,ar[100],k,y,z,b,c;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        sum =0;
        for(j=0;j<12;j++)
        {
            scanf("%lf",&arr[j]);
            sum += arr[j] ;
        }
        avg = sum/12.0 ;
        x = sum/12.0 ;
        z = x;
        j=1;
        while(x!=0)
        {
            ar[j] = x%10 ;
            x=x/10;
            j++;
        }
        b = j-1;
        y = b/3 ;
        c = 1;
        if(avg < 1000)
        {
            printf("%lld $%0.2lf\n",i,avg);
        }
        else
        {
            printf("%lld $",i);

            for(k=b;k>=2;k--)
            {
                printf("%lld",ar[k]);
                while(y>0 && (b%3==c%3))
                {
                    printf(",");
                    y--;
                    break;
                }
                c++;
            }
            a = ar[1]*1+(avg-z);
            printf("%.2lf\n",a);
        }
    }
    return 0;
}
