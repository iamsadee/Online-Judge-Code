#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool arr[1000005];
vector<ll> prime;
void seive()
{
    ll n=1000004;
    ll x=sqrt(n);
    ll i,j;
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
int main()
{
    int t,k;
    seive();
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        ll n;
        scanf("%lld",&n);
        ll sqrtt=sqrt(n);
        ll sz=prime.size();
        ll res=1;
        for(int i=0; i<sz && prime[i]<=sqrtt ; i++)
        {
            if(n%prime[i]==0)
            {
                ll cnt=0;
                while(n%prime[i]==0)
                {
                    cnt++;
                    n/=prime[i];
                }
                sqrtt=sqrt(n);
                res = res * (cnt+1);
                //cout<<cnt<<endl<<endl;
            }

        }
        if(n!=1)
        {
            res*=2;
        }
        res--;
        printf("Case %d: %lld\n",k,res);
    }
    return 0;
}
