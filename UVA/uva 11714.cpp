#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans;
    while(scanf("%lld",&n)==1)
    {
        ans = ceil(log2(n));
        ans = ans +n -2;
        printf("%lld\n",ans);
    }
    return 0;
}
