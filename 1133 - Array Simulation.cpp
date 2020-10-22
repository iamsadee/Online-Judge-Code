#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        ll arr[1005];
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='S')
            {
                ll d;
                scanf("%lld",&d);
                for(int i=0;i<n;i++)
                {
                    arr[i] += d;
                }
            }
            else if(c=='M')
            {
                ll d;
                scanf("%lld",&d);
                for(int i=0;i<n;i++)
                {
                    arr[i]=arr[i]*d;
                }
            }
            else if(c=='D')
            {
                ll d;
                scanf("%lld",&d);
                for(int i=0;i<n;i++)
                {
                    arr[i]=arr[i]/d;
                }
            }
            else if(c=='R')
            {
                reverse(arr,arr+n);
            }
            else
            {
                int x,y;
                scanf("%d %d",&x,&y);
                swap(arr[x],arr[y]);
            }
            //cout<<"done"<<endl;
        }
        printf("Case %d:\n",a);
        for(int i=0;i<n;i++)
        {
            printf("%lld",arr[i]);
            if(i==n-1)
            {
                printf("\n");
            }
            else printf(" ");
        }
    }
    return 0;
}
