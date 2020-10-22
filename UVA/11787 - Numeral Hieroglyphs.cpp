#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI acos(-1)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j;
    cin>>t;
    cin.ignore();
    map<char,ll> mp;
    mp['B']=1;
    mp['U']=10;
    mp['S']=100;
    mp['P']=1000;
    mp['F']=10000;
    mp['T']=100000;
    mp['M']=1000000;
    for(i=1; i<=t; i++)
    {
        string ch;
        cin>>ch;
        int error=0;
        int chk=0;
        int cnt=0;
        int cnt1=0;
        for(j=0;j<(ch.size()-1); j++)
        {
            if(ch[j]==ch[j+1])
            {
                cnt++;
            }
            else
            {
                if(cnt>9)
                {
                    error=1;
                    break;
                }
                cnt=0;
            }
            if(cnt>=9)
            {
                error=1;
                break;
            }
            if(mp[ch[j]]>=mp[ch[j+1]])
            {
                chk++;
            }
            if(mp[ch[j]]<=mp[ch[j+1]])
            {
                cnt1++;
            }
        }
        if(cnt>=9)
        {
            error=1;
        }
        if(error==1)
        {
            cout<<"error"<<'\n';
        }
        else if(cnt1==ch.size()-1 || chk==ch.size()-1 )
        {
            ll ans=0;
            for(j=0; j<ch.size(); j++)
            {
                ans += mp[ch[j]];
            }
            cout<<ans<<'\n';
        }
        else cout<<"error"<<'\n';
    }
    return 0;
}
