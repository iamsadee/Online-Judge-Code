#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ch[16];
ll arr[16];
int n;
ll dp[33000];
ll fun(int mask)
{
    //cout<<mask<<endl;
    //getchar();
    if(mask==((1<<n)-1))
    {
        //cout<<"sadee"<<endl;
        return 0;
    }
    if(dp[mask]!=-1)
        return dp[mask];
    ll res=1e18;
    if(mask==0)
    {
        for(int i=0; i<n; i++)
        {
            res=min(res,arr[i]+fun(mask|(1<<i)));
        }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            int lag=mask&(1<<i);
            if(lag!=0)
            {
                for(int j=0; j<n; j++)
                {
                    int req=mask&(1<<j);
                    if(req==0&& ch[i][j]!='0')
                    {
                        int y=ch[i][j]-'0';
                        ll pq=arr[j]/(y);
                        if((arr[j]%y)!=0)
                        {
                            pq++;
                        }
                        //cout<<pq<<" "<<arr[j]1<<" "<<(mask|(1<<j))<<endl;
                        res=min(res,pq+fun(mask|(1<<j)));
                    }
                    else if(req==0 && ch[i][j]=='0')
                    {
                        res=min(res,arr[j]+fun(mask|(1<<j)));
                    }
                }
            }
            else res=min(res,arr[i]+fun(mask|(1<<i)));
        }
    }
    return dp[mask]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        memset(dp,-1,sizeof dp);
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>ch[i];
        }
        ll res=fun(0);
        cout<<"Case "<<ks<<": "<<res<<endl;
    }
    return 0;
}
