#include<stdio.h>
#include<math.h>
int main()
{
    long long int l,u,n,i,j,k,mx,count,num,x;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        mx=0;
        scanf("%lld %lld",&l,&u);
        for(j=l;j<=u;j++)
        {
            x=sqrt(j);
            count=0;
            for(k=1;k<=x;k++)
            {
                if(j%k==0)
                    {
                        count++;
                        if((j%(j/k))==0 && (k !=(j/k)))
                            count++;
                    }
            }
            if(count>mx)
            {
                mx=count;
                num =j;
            }

        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,num,mx);
    }
    return 0;
}
