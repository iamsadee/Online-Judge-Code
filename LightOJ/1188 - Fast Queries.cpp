#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
ll arr[100005];
struct aa
{
    int l;
    int r;
    int pos;
    int blck;
    ll ans;
};
int blcksz;
aa A[100005];
bool cmp(aa x,aa y)
{
    if(x.blck==y.blck)
    {
        return x.r<y.r;
    }
    return x.blck<y.blck;
}
ll cnt[100005];
ll ans=0;
void rem(int x)
{
    ll y=arr[x];
    cnt[y]--;
    if(cnt[y]==0)
    {
        ans--;
    }
}
void add(int x)
{
    x=arr[x];
    cnt[x]++;
    if(cnt[x]==1)
    {
        ans++;
    }
}
bool cmpPos(aa a,aa b)
{
    return a.pos<b.pos;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,k;
    int t;
    //cin>>t;
    scanf("%d",&t);
    for(int d=1; d<=t; d++)
    {
        memset(cnt,0,sizeof cnt);
        ans=0;
        int q;
        //cin>>n;
        //cin>>q;
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            //cin>>arr[i];
            scanf("%lld",&arr[i]);
        }
        blcksz=sqrt(n);
        for(int i=0; i<q; i++)
        {
            int x,y;
            //cin>>x>>y;
            scanf("%d %d",&x,&y);
            A[i].l=x-1;
            A[i].r=y-1;
            A[i].pos=i;
            A[i].blck=(x-1)/blcksz;
        }
        sort(A,A+q,cmp);
        int L=0;
        int R=-1;
        for(int i=0; i<q; i++)
        {
            //cout<<A[i].l<<" "<<A[i].r<<endl;
            while(L<A[i].l)
            {
                rem(L);
                L++;
            }
            while(R>A[i].r)
            {
                rem(R);
                R--;
            }
            while(L>A[i].l)
            {
                L--;
                add(L);
            }
            while(R<A[i].r)
            {
                R++;
                add(R);
            }
            A[i].ans=ans;
        }
        sort(A,A+q,cmpPos);
        //cout<<"Case "<<d<<":\n";
        printf("Case %d:\n",d);
        for(int i=0; i<q; i++)
        {
            printf("%lld\n",A[i].ans);
        }
    }


    return 0;
}
