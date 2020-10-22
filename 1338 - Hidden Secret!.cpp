#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI acos(-1)
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int t;
    cin>>t;
        cin.ignore();
    for(int a=1;a<=t;a++)
    {
        string aa,b;
        getline(cin,aa);
        getline(cin,b);
        //cout<<aa<<endl;
        //cout<<b<<endl;
        map<char,int> mp,mp1;
        string ch=aa;
        for(int i=0;i<aa.size();i++)
        {
            if(ch[i]>='A' && ch[i]<='Z')
            {
                mp[ch[i]+32]++;
            }
            else mp[ch[i]] ++;
        }
        ch=b;
        for(int i=0;i<b.size();i++)
        {
            if(ch[i]>='A' && ch[i]<='Z')
            {
                mp1[ch[i]+32]++;
            }
            else mp1[ch[i]] ++;
        }
        bool chk=0;
        for(char i='a';i<='z';i++)
        {
            if(mp[i]!=mp1[i])
            {
                chk=1;
                break;
            }
        }
        if(chk)
            printf("Case %d: No\n",a);
        else printf("Case %d: Yes\n",a);
    }
    return 0;
}
