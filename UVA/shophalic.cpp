#include<bits/stdc++.h>
using namespace std;

int main()

{

    int t , n , price[20000] , i , j  , sum ,c;

    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&price[j]);
        }
        sort(price,price+n,std::greater<int>());
        sum = 0;
        for(c=2;c<n;c=c+3)
        {
            sum =sum + price[c] ;
        }
        printf("%d\n",sum);

    }
    return 0;
}
