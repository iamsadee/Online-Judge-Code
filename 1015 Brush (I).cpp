#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int i,j,n;
    int t,q;
    scanf("%d",&t);
    int a[1005];
    for(int m=1;m<=t;m++)
    {
        scanf("%d",&n);
        ll sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]>0)
            sum +=a[i];
        }
        printf("Case %d: %lld\n",m,sum);
    }

    return 0;
}
