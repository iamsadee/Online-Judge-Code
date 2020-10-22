#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll arr[1005];
int day=0;
ll bin()
{
    ll low=0;
    ll high=1e9;
    ll ans=0;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        int x=n+1;
        ll sum=0;
        bool chk=0;
        int cnt=0;
        for(int i=1;i<=x;i++)
        {
            if(arr[i]>mid)
            {
                chk=1;
                break;
            }
            if((sum+arr[i])<=mid)
            {
                sum += arr[i];
            }
            else
            {
                cnt++;
                sum =arr[i];
            }
        }
        if(sum!=0 && sum<=mid)
        {
            cnt++;
        }
        int y=k+1;
        //cout<<cnt<<" "<<mid<<" "<<chk<<endl;
        if(cnt>y || chk==1)
        {
            low=mid+1;
        }
        else if(cnt<y  )
        {
            day=cnt;
            high=mid-1;
            ans=mid;
        }
        else
        {
            day=cnt;
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        scanf("%d %d",&n,&k);
        int x=n+1;
        arr[0]=0;
        for(int i=1;i<=x;i++)
        {
            scanf("%lld",&arr[i]);
        }
        day=0;
        ll z=bin();
        printf("Case %d: %lld\n",a,z);
        ll sum=0;
        int y=k+1;
        int cnt=0;
        for(int i=1;i<=x;i++)
        {
            int baki=x-(i-1);
            //cout<<sum<<" "<<baki<<" "<<y-cnt<<endl;
            if((baki<(y-cnt)))
            {
                if(sum<=z)
                {
                    printf("%lld\n",sum);
                    cnt++;
                    int q=i;
                    for(int j=q;j<=x;j++)
                    {
                        printf("%lld\n",arr[j]);
                    }
                }
                sum=0;
                break;
            }
            sum += arr[i];
            if(sum>z)
            {
                cnt++;
                sum -= arr[i];
                printf("%lld\n",sum);
                sum=arr[i];
            }
        }
        if(sum!=0)
            printf("%lld\n",sum);

    }
    return 0;
}
