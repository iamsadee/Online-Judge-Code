
#include<bits/stdc++.h>
using namespace std;
int prime(int n)
{
    int x,i;
    x=sqrt(n);
    for(i=2;i<=x;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n ,t,i,j,x;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        x=n/2+1;
        while(!prime(x))
        {
            x++;
        }
        printf("%d\n",x);
    }
    return 0;
}
