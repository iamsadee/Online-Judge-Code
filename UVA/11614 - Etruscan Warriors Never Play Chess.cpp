#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,i,j,x,y,n;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        x=(-1+sqrt(1+4*1*(2*n)))/2;
        printf("%lld\n",x);
    }
    return 0;
}
