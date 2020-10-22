#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll n;
        scanf("%lld",&n);
        int cnt=0;
        while(n!=0)
        {
            if(n%2==1)
            {
                cnt++;
            }
            n=n/2;
        }
        if(cnt%2)
        {
            printf("Case %d: odd\n",a);
        }
        else printf("Case %d: even\n",a);
    }
    return 0;
}
