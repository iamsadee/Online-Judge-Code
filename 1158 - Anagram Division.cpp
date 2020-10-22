#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1026][1003];
string ch;
int d;
int pre[105];
int bin(int st)
{
    int low=st;
    int high=ch.size()-1;
    int ans=ch.size();
    while(low<=high)
    {
        int mid=(low+high)/2;
        if((ch[mid]-'0')>(ch[st-1]-'0'))
        {
            high=mid-1;
            ans=mid;
        }
        else
        {
            low=mid+1;
            //ans=mid;
        }
    }
    return ans;
}
int n;
int fun(int mask,int sum)
{
    //cout<<mask<<endl;
    if(mask==((1<<n)-1))
    {
        if(sum==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[mask][sum]!=-1)
        return dp[mask][sum];
    ll res=0;
    for(int i=0; i<ch.size(); )
    {
        int nibo=mask&(1<<i);
        if(nibo ==0)
        {
            //cout<<(mask|i)<<endl;
            res += fun((mask|(1<<i)),((sum*10)+(ch[i]-'0'))%d);
            i=pre[i];
        }
        else i++;

    }
    return dp[mask][sum]=res;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int ks=0;
    while(t--)
    {
        cin>>ch;
        cin>>d;
        sort(ch.begin(),ch.end());
        n=ch.size();
        for(int i=0;i<n;i++)
        {
            pre[i]=bin(i+1);
        }
        memset(dp,-1,sizeof dp);
        ks++;
        cout<<"Case "<<ks<<": "<<fun(0,0)<<"\n";
    }
    return 0;
}
