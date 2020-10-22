#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[18][2][2][2][18];
string a;
int n;
ll fun(int l,int choto,int force,int suru,int r)
{
    if(l>r)
    {
        if(choto ==0 && force==1)
            return 0;
        else return 1LL;

    }
    if(dp[l][choto][force][suru][r]!=-1)
    {
        return dp[l][choto][force][suru][r];
    }
    ll res=0;
    int low=0;
    int high=9;
    if(choto==0)
    {
        high=a[l]-'0';
    }
    for(int i=low; i<=high; i++)
    {
        if(i==0 && suru==0)
        {
            res += fun(l+1,choto|(i<high),force,suru|(i>0),r);
        }
        else if(i==(a[r]-'0'))
        {
            res += fun(l+1,choto|(i<high),force,suru|(i>0),r-1);
        }
        else if(i<(a[r]-'0'))
        {
            res += fun(l+1,choto|(i<high),0,suru|(i>0),r-1);
        }
        else
        {
            res += fun(l+1,choto|(i<high),1,suru|(i>0),r-1);
        }
    }
    return dp[l][choto][force][suru][r]=res;

}
ll make(ll x)
{
    if(x<0) return 0;
    a.clear();
    if(x==0) a.push_back('0');
    while(x>0)
    {
        a.push_back((x%10)+'0');
        x=x/10;
    }
    reverse(a.begin(),a.end());
    n=a.size()-1;
    memset(dp,-1,sizeof dp);
    ll res=fun(0,0,0,0,n);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cout<<make(0)<<endl;
    int t;
    cin>>t;
    int ks=0;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        ks++;
        cout<<"Case "<<ks<<": "<<make(y)-make(x-1)<<endl;
    }
    return 0;
}
