#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct A
{
    ll x,y;
};
bool cmp(A a,A b)
{

    return a.y<b.y;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        ll n,w;
        scanf("%lld %lld",&n,&w);
        A arr[50005];
        for(int j=1;j<=n;j++)
        {
            ll x,y;
            scanf("%lld %lld",&x,&y);
            arr[j].x=x;
            arr[j].y=y;
        }
        sort(arr+1,arr+(n+1),cmp);
        ll res=-1e15;
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(arr[j].y<=res)
            {
                while(j<=n && arr[j].y<=res)
                {
                    j++;
                }
                j--;
            }
            else
            {
                res=arr[j].y+w;
                cnt++;
            }
        }
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}
