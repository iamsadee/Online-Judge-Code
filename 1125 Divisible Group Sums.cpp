#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,d;
int q;
ll arr[205];
ll dp[203][12][21][21];
ll fun(int pos,int nisi,int posi,int neg)
{
    if(nisi>m) return 0;
    if(pos>=n)
    {
        int sum = (posi+neg)%d;
        if(nisi==m && sum%d==0)
        {
            //cout<<"sum "<<sum<<" "<<nisi<<" "<<m<<endl;
            return 1LL;
        }
        return 0;
    }
    if(dp[pos][nisi][posi][neg]!=-1)
        return dp[pos][nisi][posi][neg];
    ll res=0;
    ll a=posi;
    ll b=neg;
    if(arr[pos]>0)
    {
        a=a+arr[pos];
        a=a%d;
    }
    else
    {
        b=b+arr[pos];
        b=b%d;
    }
    res += fun(pos+1,nisi+1,a,b);
    res += fun(pos+1,nisi,posi,neg);
    return dp[pos][nisi][posi][neg]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    //cout<<(-15%4)<<endl;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        printf("Case %d:\n",ks);
        for(int i=0; i<q; i++)
        {
            memset(dp,-1,sizeof dp);
            scanf("%d %d",&d,&m);
            ll req=fun(0,0,0,0);
            printf("%lld\n",req);
        }
    }
    return 0;
}
