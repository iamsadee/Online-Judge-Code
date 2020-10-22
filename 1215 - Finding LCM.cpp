#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool arr[1000005];
vector<ll> prime;
void seive()
{
    int n=1000005;
    int x=sqrt(n);
    int i,j;
    arr[0]=1;
    arr[1]=1;
    for(i=4; i<=n; i+=2)
    {
        arr[i]=1;
    }
    for(i=3; i<=x; i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i; j<=n; j+=2*i)
            {
                arr[j]=1;
            }
        }
    }
    for(i=2; i<=n; i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}
vector<pair<ll,ll> > factor;
void fact(ll x)
{
    ll sq=sqrt(x);
    for(int i=0; i<prime.size() && prime[i]<=sq; i++ )
    {
        if(x%prime[i]==0)
        {
            ll cnt=0;
            while(x%prime[i]==0)
            {
                x=x/prime[i];
                cnt++;
            }
            factor.push_back(make_pair(prime[i],cnt));
        }
        sq=sqrt(x);
    }
    if(x!=1)
    {
        factor.push_back(make_pair(x,1LL));
    }
}

vector<ll> divisor;
void setDiv(ll n,ll i)
{
    for(ll j=i; j<factor.size(); j++)
    {
        ll x=factor[j].first*n;
        for(ll k=0; k<factor[j].second; k++)
        {
            divisor.push_back(x);
            setDiv(x,j+1);
            x *= factor[j].first;
        }
    }
}

int main()
{

    int t;
    seive();
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        ll a,b,l;
        scanf("%lld %lld %lld",&a,&b,&l);
        factor.clear();
        divisor.clear();
        if(l%a !=0 || l%b!=0)
        {
            printf("Case %d: impossible\n",i);
        }
        else
        {
            divisor.push_back(1);
            fact(l);
            setDiv(1,0);
            sort(divisor.begin(),divisor.end());
            ll gcd=__gcd(a,b);
            ll lcm=(a*b)/gcd;
            //cout<<lcm<<" "<<gcd<<endl;
            //cout<<a<<" "<<b<<endl;
            for(int k=0;k<divisor.size();k++)
            {
                ll res=(lcm*divisor[k])/__gcd(divisor[k],lcm);
                if(res==l)
                {
                    printf("Case %d: %lld\n",i,divisor[k]);
                    break;
                }
            }

        }

    }


    return 0;
}
