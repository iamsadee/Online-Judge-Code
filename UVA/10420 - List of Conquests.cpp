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
        cin.ignore();
        string ch[2005],name[2005];
        map<string,int> mp;
        map<string,int> :: iterator it;
        for(int i=1;i<=n;i++)
        {
            cin>>ch[i];
            getline(cin,name[i]);
            mp[ch[i]] +=1;
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            cout<<(*it).first<<' '<<(*it).second<<'\n';
        }
    }
    return 0;
}
