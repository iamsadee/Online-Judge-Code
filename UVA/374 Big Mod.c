#include<stdio.h>
int main()
{
    long long int y,b,p,m,x,power,arr[100000],i,j,k;
    while(scanf("%lld %lld %lld",&b,&p,&m)==3)
    {
        k=0;
        while(p!=0)
        {
            arr[k]=p%2;
            p=p/2;
            k++;
        }
        x=1;
        power = b%m;
        for(i=0;i<k;i++)
        {
            if(arr[i]==1)
                x = (x*power)%m;
            power = (power * power)%m;
        }
        printf("%lld\n",x);
    }
    return 0;
}
