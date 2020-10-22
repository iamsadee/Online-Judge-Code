#include<stdio.h>
int main()
{
    long long int a , b ,i,j,n,arr[5],k,m,count,l,x;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        count=0;
        for(i=a;i<=b;i++)
        {
            n=i;
            j=0;
            while(n!=0)
            {
                arr[j]=n%10;
                n=n/10;
                j++;
            }
            l=1;
            x=j-1;
            for(k=0;k<=x;k++)
            {
                for(m=k+1;m<=x;m++)
                {
                    if(arr[m]==arr[k])
                    {
                        l=0;
                        break;
                    }
                }
                if(l==0)
                    break;
            }
            if(l!=0)
                count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
