#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll c=min(a,b);
        ll d=max(a,b);
        a=c;
        b=d;
        ll x=(b/(ll)30);
        ll cnt1=x*(ll)(20);
        ll y=x*30 +1LL;
        ll sum=0;
        //cout<<y<<endl;
        for(ll j=y;j<=b;j++)
        {
            sum += j;
            //sum = sum%3;
            if(sum%3==0)
            {
                cnt1++;
            }
        }
        //cout<<cnt1<<endl;
        x=(a-1LL)/(ll)30;
        ll cnt=x*(ll)(20);
        y= x*30 +1LL;
        sum=0;
        //cout<<cnt<<endl;
        for(ll j=y;j<a;j++)
        {
            sum += j;
            //sum = sum%3;
            if(sum%3==0)
            {
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        ll ans=cnt1-cnt;
        printf("Case %d: %lld\n",i,ans);

    }
    return 0;
}
