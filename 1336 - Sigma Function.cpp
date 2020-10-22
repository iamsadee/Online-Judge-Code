#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int t;
    scanf("%d",&t);
    for(int j=1; j<=t; j++)
    {
        ll n;
        scanf("%lld",&n);
        ll tmp=sqrt(n/2);
        ll res=sqrt(n)-tmp;
        res += (tmp)*2;
        res = n-res;
        printf("Case %d: %lld\n",j,res);

    }
    return 0;
}
