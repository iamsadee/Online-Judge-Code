#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        map<ll,ll> mp;
        map<ll,ll>::iterator it;
        if(n==0)
            break;
        int i,j,k;
        ll x,y,z;
        ll ans=0;
        for(i=1; i<=n; i++)
        {
            cin>>k;
            for(j=1; j<=k; j++)
            {
                cin>>x;
                mp[x]+=1;
            }
            it=mp.begin();
            y=(*it).first;
            //cout<<y<<endl;
            mp[y] -=1;
            if(mp[y]==0)
            {
                mp.erase(y);
            }
            it=mp.end();
            it--;
            z=(*it).first;
            //cout<<z<<endl;
            mp[z] -=1;
            if(mp[z]==0)
            {
                mp.erase(z);
            }
            ans += abs(y-z);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
