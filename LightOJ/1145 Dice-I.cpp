#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    ll i,j,k,n,face,sum;
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld %lld",&n,&face,&sum);
        ll ar[15005],arr[15005];
        memset(ar,0,sizeof arr);
        memset(arr,0,sizeof ar);
        //ar[0]=1;
        for(j=1;j<=face;j++)
        {
            arr[j]=1;
        }
        for(j=2;j<=n;j++)
        {
            for(k=1;k<=sum;k++)
            {
                if(j%2==1)
                {
                    arr[k]=(ar[k-1]%100000007+arr[k-1]%100000007)%100000007;
                    if(k-face>0)
                    {
                        arr[k] = (arr[k]%100000007-ar[k-face-1]%100000007)%100000007;
                    }
                }
                else
                {
                    //cout<<ar[k-1]<<" "<<arr[k-1]<<"  ";
                    ar[k]=(ar[k-1]%100000007+arr[k-1]%100000007)%100000007;

                    if(k-face>0)
                    {
                        ar[k] = (ar[k]%100000007-arr[k-face-1]%100000007)%100000007;
                    }
                    //cout<<ar[k]<<endl;
                }
            }
        }
        if(n%2==1)
        {
            if(arr[sum]<0)
            {
                arr[sum]+= 100000007;
                arr[sum] %= 100000007;
            }
            printf("Case %lld: %lld\n",i,arr[sum]);
        }
        else
        {
            if(ar[sum]<0)
            {
                ar[sum]+= 100000007;
                ar[sum] %= 100000007;
            }
            printf("Case %lld: %lld\n",i,ar[sum]);
        }

    }


    return 0;
}
