#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ch;
int chk;
bool vow(char c)
{
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
    return false;
}
int  dp[51][2][51][51];
int x,y;
int fun(int pos,int prev,int vo,int con)
{
    //cout<<pos<<" "<<vo<<" "<<con<<endl;
    if((vo)>=3) x=1;
    if(con>=5) x=1;
    if(pos>=ch.size())
    {
        return !prev;
    }
    if(dp[pos][prev][vo][con]!=-1)
        return dp[pos][prev][vo][con];
    int res=0;
    if(ch[pos]=='?')
    {
        int res1=fun(pos+1,prev|((vo+1)>=3),vo+1,0);
        res=max(res,res1);
        res1=fun(pos+1,prev|((con+1)>=5),0,con+1);
        res=max(res,res1);
    }
    else if(vow(ch[pos]))
    {
        int res1=fun(pos+1,prev|((vo+1)>=3),vo+1,0);
        res=max(res,res1);
    }
    else
    {
        int res1=fun(pos+1,prev|((con+1)>=5),0,con+1);
        res=max(res,res1);
    }
    return dp[pos][prev][vo][con]=res;
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
        cin>>ch;
        int cnt=0;
        int cnt1=0;
        chk=0;
        for(int i=0; i<ch.size(); i++)
        {
            if(ch[i]!='?')
            {
                if(vow(ch[i]))
                {
                    cnt1=0;
                    cnt++;
                    if(cnt>=3)
                    {
                        chk=1;
                    }
                }
                else
                {
                    cnt=0;
                    cnt1++;
                    if(cnt1>=5)
                    {
                        chk=1;
                    }
                }
            }
            else
            {
                cnt=0;
                cnt1=0;
            }
        }
        cout<<"Case "<<ks<<": ";
        if(chk==1)
        {
            cout<<"BAD"<<endl;
        }
        else
        {
            x=0,y=0;
            y=fun(0,0,0,0);
            //cout<<x<<" "<<y<<endl;
            if(x==1 && y==1)
            {
                cout<<"MIXED"<<endl;
            }
            else if(x==1 && y==0)
            {
                cout<<"BAD"<<endl;
            }
            else cout<<"GOOD"<<endl;
        }
    }
    return 0;
}
