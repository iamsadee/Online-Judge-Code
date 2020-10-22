#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n;
        scanf("%d",&n);
        ll sum=0;
        printf("Case %d:\n",a);
        for(int i=0;i<n;i++)
        {
            string ch;
            cin>>ch;
            if(ch=="donate")
            {
                ll x;
                scanf("%lld",&x);
                sum +=x;
            }
            else
            {
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}
