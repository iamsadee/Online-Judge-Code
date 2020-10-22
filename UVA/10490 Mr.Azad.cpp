#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int prime(int x)
{
    int n=sqrt(x);
    int i;
    for(i=2;i<=n;i++)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        int x=pow(2.0,n*1.0)-1;
        if(prime(n)==1 && prime(x)==1 )
        {
            ll y=pow(2.0,(n-1)*1.0)*(pow(2.0,n*1.0)-1);
            printf("Perfect: %lld!\n",y);
        }
        else if(prime(n)==1 && prime(x)!=1)
        {
            printf("Given number is prime. But, NO perfect number is available.\n");
        }
        else if(prime(n)==0)
        {
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
    return 0;
}
