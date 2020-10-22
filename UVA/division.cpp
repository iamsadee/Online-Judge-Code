#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dig(ll x)
{
    int chk=0;
    while(x!=0)
    {
        x=x/10;
        chk++;
    }
    if(chk==5) return 1;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> node[1005];
    for(ll i=2;i<=79;i++)
    {
        for(ll j=1000;j<=99999;j++)
        {
            map<ll,bool> mp;
            ll x=i*j;
            if(x>99999)
                break;
            else
            {
                ll a=x;
                ll b=j;
                int chk=0;
                while(a!=0)
                {
                    mp[a%10]=1;
                    a=a/10;
                    chk++;
                }
                if((5-chk)>0 && (5-chk)<2)
                {
                    mp[0]=1;
                }
                chk=0;
                while(b!=0)
                {
                    mp[b%10]=1;
                    b=b/10;
                    chk++;
                }
                if((5-chk)>0 && (5-chk)<2)
                {
                    mp[0]=1;
                }
                int cnt=0;
                for(int k=0;k<10;k++)
                {
                    if(mp[k]==1)
                    {
                        cnt++;
                    }
                }
                if(cnt==10)
                {
                    node[i].push_back(x);
                    node[i].push_back(j);
                }
            }
        }
    }
    int n;
    int k=0;
    while(cin>>n)
    {
        if(n==0)
            break;
        k++;
        if(k>1)
        {
            cout<<"\n";
        }
        for(int i=0;i<node[n].size();i+=2)
        {
            ll x=node[n][i];
            ll y=node[n][i+1];
            if(dig(x))
            {
                cout<<x<<" "<<"/ ";
                if(dig(y))
                {
                    cout<<y<<" = "<<n<<"\n";
                }
                else cout<<0<<y<<" = "<<n<<"\n";
            }
            else
            {
                cout<<0<<x<<" "<<"/ ";
                cout<<y<<" = "<<n<<"\n";
            }
        }
        if(node[n].size()==0)
        {
            cout<<"There are no solutions for "<<n<<"."<<"\n";
        }
    }


    return 0;
}
