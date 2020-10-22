#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[21][2][2][2][21];
string a,b;
int n;
ll fun(int pos,int boro,int choto,int suru,int cnt)
{
    //cout<<pos<<endl;
    if(pos==n)
        return cnt;
    if(dp[pos][boro][choto][suru][cnt]!=-1)
    {
        return dp[pos][boro][choto][suru][cnt];
    }
    int lw=0,hi=9;
    if(boro==0) lw=a[pos]-'0';
    if(choto==0) hi=b[pos]-'0';
    ll ret=0;
    //cout<<lw<<" "<<hi<<endl;
    for(int i=lw; i<=hi; i++)
    {
        if(i==0 && suru==1)
        {
            ret += fun(pos+1,boro|(i>lw),choto|(i<hi),suru|(i>0),cnt+1);
        }
        else
        {
            ret += fun(pos+1,boro|(i>lw),choto|(i<hi),suru|(i>0),cnt);
        }
    }
    return dp[pos][boro][choto][suru][cnt]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int k=0;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        cin>>a>>b;
        ll ans=0;
        if(a.size()==1 && a[0]=='0') ans=1;
        n=max(a.size(),b.size());
        string tmp;
        int x=n-a.size();
        for(int i=1; i<=x; i++)
        {
            tmp.push_back('0');
        }
        tmp +=a;
        a=tmp;
        //cout<<a<<' '<<b<<endl;
        ans+=fun(0,0,0,0,0);
        k++;
        cout<<"Case "<<k<<": "<<ans<<endl;
    }
    return 0;
}
