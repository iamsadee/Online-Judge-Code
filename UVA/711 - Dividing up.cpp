#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[7];
int dp[7][120005];
int tot=0;
int tot1;
int flag=0;
int fun(int pos,int sum)
{
    if(flag) return 1;
    if(sum>(tot1))
        return 0;
    if(sum==tot1)
        {
            flag=1;
            return 1;
        }
    if(pos>6)
    {
        if(sum==tot1)
        {
            return 1;
        }
        else return 0;
    }
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    int ans=0;
    for(int i=0;i<=arr[pos];i++)
    {
        ans=max(ans,fun(pos+1,sum+(i*pos)));
    }
    return dp[pos][sum]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ks=1;
    bool chk=1;
    while(chk)
    {
        int cnt=0;
        tot=0;
        for(int i=1; i<=6; i++)
        {
            cin>>arr[i];
            tot += (i*arr[i]);
            if(arr[i]==0) cnt++;
        }
        if(tot==0)
        {
            break;
        }
        tot1=tot/2;
        cout<<"Collection #"<<ks<<":\n";
        if(tot%2)
        {
            cout<<"Can't be divided.\n\n";
        }
        else
        {
            flag=0;
            memset(dp,-1,sizeof dp);
            int ans=fun(1,0);
            if(ans==0) cout<<"Can't be divided.\n\n";
            else cout<<"Can be divided.\n\n";
        }
        ks++;
    }
    return 0;
}
