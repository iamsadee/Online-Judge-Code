#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll arr[101][101];
    int n,i,j;
    while(scanf("%d",&n)==1)
    {
        ll a[n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lld",&arr[i][j]);
            }
        }
        ll mxsum=-10000000000;
        for(i=0;i<n;i++)
        {
            memset(a,0,sizeof a);
            for(j=i;j<n;j++)
            {
                ll sum=0;
                for(int k=0;k<n;k++)
                {
                    a[k] += arr[j][k];
                    sum += a[k];
                    if(sum<0)
                    {
                        sum=0;
                    }
                    if(mxsum<sum)
                    {
                        mxsum=sum;
                    }
                }
            }
        }
        printf("%lld\n",mxsum);
    }
    return 0;
}
