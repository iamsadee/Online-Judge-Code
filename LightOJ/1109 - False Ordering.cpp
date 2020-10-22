#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//static double arr[1000005];
//arr[0]=0.0;
struct di{
    int num,value;

};
bool cmp(di a,di b)
{
    if(a.num==b.num)
        return a.value>b.value;
    else return a.num<b.num;
}
di arr[1005];
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    arr[0].num=1;
    arr[0].value=1;
    for(int i=2;i<=1000;i++)
    {
        int x=sqrt(i);
        int n=i;
        int cnt=0;
        for(int j=1;j<=x;j++)
        {
            if(n%j==0)
            {
                cnt++;
                if(n%(n/j)==0 && (n/j)!=j)
                {
                    cnt++;
                }
            }
        }
        arr[i-1].num=cnt;
        arr[i-1].value=i;
    }
    sort(arr,arr+1000,cmp);
    int t;
    scanf("%d",&t);
    int i,j,k;
    for(i=1;i<=t;i++)
    {
        ll p,q,n,r;
        scanf("%lld",&n);
        printf("Case %d: %d\n",i,arr[n-1].value);
    }
    return 0;
}
