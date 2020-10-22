#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        cin>>a>>b;
        ll x=abs(a-b) * ll(4);
        x += (3+5+3);
        x += abs(0-a)*4;
        x += (3+5);
        printf("Case %d: %lld\n",i,x);
    }
    return 0;
}

