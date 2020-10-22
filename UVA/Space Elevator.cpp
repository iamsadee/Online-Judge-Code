#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
string a,b;
int kot;
ll dp[22][2][10];
int vis[22][2][10];
ll fun(int pos,int choto,int prev)
{
    if(pos==kot)
    {
        return (ll)1;
    }
    if(vis[pos][choto][prev]!=-1)
        return dp[pos][choto][prev];
    ll ret=0;
    int hi=9;
    if(choto==0) hi=b[pos]-'0';
    for(int i=0; i<=hi; i++)
    {
        if(prev==1)
        {
            if(i!=3 && i!=4)
            {
                ret += fun(pos+1,choto|(i<hi),i);
            }
        }
        else
        {
            if(i!=4)
            {
                ret += fun(pos+1,choto|(i<hi),i);
            }
        }
    }
    vis[pos][choto][prev]=1;
    return dp[pos][choto][prev]=ret;
}

void make(unsigned long long x)
{
    b.clear();
    while(x!=0)
    {
        b.push_back((x%10LL)+'0');
        x=x/(ll)10;
    }
    reverse(b.begin(),b.end());
    kot=b.size();
    //cout<<b<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);//ans.clear();
    ll n;
    while( cin>>n)
    {
        n++;
        ll low=1;
        ll high=18446744073709551615;
        ll ans=0;
        while(low<=high)
        {
            memset(vis,-1,sizeof vis);
            ll mid=low + ((high - low) / (ll)2);
            make(mid);
            ll res=fun(0,0,0);
            //cout<<mid<<" "<<res<<endl;
            if(res==n)
            {
                ans=mid;
                high=mid-1;
                //break;
            }
            else if(res>n)
            {
                high=mid-(ll)1;
            }
            else
            {
                low=mid+(ll)1;
            }
        }

        cout<< ans<<endl;
    }
    //myfile1.close();
    return 0;
}
