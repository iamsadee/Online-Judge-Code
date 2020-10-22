#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    */
    ll sum=1;
    ll fac[25];
    fac[0]=1;
    for(ll i=1;i<=19;i++)
    {
        sum = sum*i;
        fac[i]=sum;
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll n;
        scanf("%lld",&n);
        vector<ll> ans;
        int k=19;
        while(n>0 && k>=0)
        {
            ll x=0;
            int l=-1;
            for(int j=0;j<=k;j++)
            {
                //cout<<fac[j]<<endl;
                if(n>=fac[j])
                {
                    x=fac[j];
                    l=j;
                    //cout<<x<<endl;
                }
                else break;
            }
            n-=x;
            ans.push_back(l);
            k=l-1;
        }
        //cout<<n<<endl;
        if(n<0 || n>0)
        {
            printf("Case %d: impossible\n",i);
        }
        else
        {
            printf("Case %d: ",i);
            for(int j=ans.size()-1;j>=0;j--)
            {
                printf("%lld!",ans[j]);
                if(j==0)
                    printf("\n");
                else printf("+");
            }
        }

    }
    return 0;
}
