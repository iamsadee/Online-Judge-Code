#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a,b,c,d;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
    {
        if(a==0 && b==0 && c==0 && d==0)
        {
            break;
        }
        ll ans = 120;
        if(b>a)
        {
            ans += (a+(40-b));
        }
        else if(a>=b)
        {
            ans += (a-b);
        }
        if(c>b)
        {
            ans += (c-b);
        }
        else if(c<=b)
        {
            ans += (40-b)+c;
        }
        if(d>c)
        {
            ans += (c+(40-d));
        }
        else if(c>=d)
        {
            ans += (c-d);
        }
        printf("%lld\n",ans*9);
    }
    return 0;
}
