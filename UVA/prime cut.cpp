#include<bits/stdc++.h>
using namespace std;
int prime(int x)
{
    int i,n;
    n=sqrt(x);
    for(i=2;i<=n;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int arr[1001],n,c,x,y,i,j,z,a=0;
    while(scanf("%d %d",&n,&c)==2)
    {
        j=1;
        for(i=1;i<=n;i++)
        {
            if(prime(i))
            {
                arr[j]=i;
                j++;
            }
        }
        j--;
        if(j%2==1)
        {
            x=2*c-1;
        }
        else
        {
            x=2*c;
        }
        if(x>=j)
        {
            printf("%d %d: ",n,c);
            for(i=1;i<=j;i++)
            {
                printf("%d",arr[i]);
                if(i!=j)
                    printf(" ");
            }
            printf("\n\n");
        }
        else
        {
            y=j-x;
            z=y/2+1;
            printf("%d %d: ",n,c);
            for(i=z;i<(z+x);i++)
            {
                printf("%d",arr[i]);
                if(i!=(z+x-1))
                    printf(" ");
            }
            printf("\n\n");
        }
    }
    return 0;
}

