#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int k;
        scanf("%d",&k);
        ll sum=0;
        for(int j=1;j<=k;j++)
        {
            ll x,y;
            scanf("%lld %lld",&x,&y);
            sum =sum^(y-x-1);
        }
        if(sum!=0)
            printf("Case %d: Alice\n",i);
        else printf("Case %d: Bob\n",i);
    }

    return 0;

}
