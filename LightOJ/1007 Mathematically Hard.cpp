#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//bool vis[5000005];
ll phi[5000005];
void seive()
{
    //vis[0]=1;
    //vis[1]=1;
    ll n=sqrt(5000005);
    ll i,j;
    for(ll i=2;i<=5000000;i++)
    {
        phi[i]=i;
    }
    for(i=2;i<=5000000;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(j=i*2;j<=5000000;j+=i)
            {
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}
int main()
{
    int t;
    seive();
    ll j;
    //vector<ll> ans;
    ll res=0;
    //ans.push_back(0);
    for(j=2;j<=5000000;j++)
    {
        ll x=phi[j];
        res += (x*x);
        phi[j]=res;
    }
    phi[1]=0;
    scanf("%d",&t);
    int i;
    ll a , b;
    for(i=1;i<=t;i++)
    {
        scanf("%llu %llu",&a,&b);
        printf("Case %d: %llu\n",i,phi[b]-phi[a-1]);
    }
    return 0;
}


