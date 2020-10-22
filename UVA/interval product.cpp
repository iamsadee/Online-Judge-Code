#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
ll arr[100005];
ll mul[1005];
int blcksz;
int n;
void update(int x,ll val)
{
    int block=x/blcksz;
    arr[x]=val;
    ll multi=1LL;
    int start=block*blcksz;
    int stop=start+blcksz;

    for(int i=start;i<stop && i<n;i++)
    {
        multi *= arr[i];
    }
    mul[block]=multi;
}
ll query(int l,int r)
{
    ll ans=1LL;
    while(l<r && l%blcksz!=0 && l!=0 )
    {
        ans *= arr[l];
        l++;
    }
    //cout<<ans<<endl;
    while(l+blcksz <= r)
    {
        ans *= mul[l/blcksz];
        l += blcksz;
    }
    while(l<=r)
    {
        ans *= arr[l];
        l++;
    }
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    while(cin>>n)
    {
        cin>>m;
        blcksz=(sqrt(n));
        //cout<<blcksz<<endl;
        int blckid=-1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]<0)
            {
                arr[i]=-1;
            }
            else if(arr[i]>0)
            {
                arr[i]=1;
            }
            if(i%blcksz==0)
            {
                blckid++;
                mul[blckid]=1LL;
            }
            mul[blckid] *= arr[i];
        }
        //cout<<blckid<<endl;
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            if(c=='C')
            {
                int x;
                ll val;
                cin>>x>>val;
                if(val>0)
                {
                    val=1;
                }
                else if(val<0)
                {
                    val=-1;
                }
                update(x-1,val);
                //cout<<mul[0]<<endl;
            }
            else
            {
                int x,y;
                cin>>x>>y;
                ll ans=query(min(x-1,y-1),max(y-1,x-1));
                //cout<<ans<<endl;
                if(ans==0)
                {
                    cout<<0;
                }
                else if(ans<0)
                {
                    cout<<"-";
                }
                else cout<<"+";
            }
        }
        cout<<endl;

    }
    return 0;
}
