#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n , arr[10000],i,j,k,temp,mx,z=1;
    while(scanf("%lld",&n)==1)
    {
       for(i=0;i<n;i++)
       {
           scanf("%lld",&arr[i]);
       }
       mx=0;
       for(i=0;i<n;i++)
       {
           for(j=i;j<n;j++)
           {
               temp=1;
               for(k=i;k<=j;k++)
               {
                   temp *= arr[k];
               }
               if(temp>mx)
                mx=temp;
           }
       }
       if(mx>0)
             printf("Case #%lld: The maximum product is %lld.\n",z,mx);
       else printf("Case #%lld: The maximum product is 0.\n",z);
       printf("\n");
       z++;
    }
    return 0;
}
