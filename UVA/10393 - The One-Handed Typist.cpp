#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    string a[12];
    a[1]="qaz";
    a[2]="wsx";
    a[3]="edc";
    a[4]="rfvtgb";
    a[5]=" ";
    a[6]=" ";
    a[7]="yhnujm";
    a[8]="ik,";
    a[9]="ol.";
    a[10]="p;/";
    int i,j;
    while(cin>>n>>m)
    {
        int x;
        map<char,bool> mp;
        set<string> st;
        string ch;
        for(i=1;i<=n; i++)
        {
            cin>>x;
            for(j=0; j<a[x].size(); j++)
            {
                mp[a[x][j]] =1;
            }
        }
        cin.ignore();
        int mx=0;
        int cnt=0;
        for(j=0; j<m; j++)
        {
            cin>>ch;
            int chk=0;
            for(i=0; i<ch.size(); i++)
            {
                if(mp[ch[i]]==1)
                {
                    chk=1;
                    break;
                }
            }
            if(chk==0)
            {
                st.insert(ch);
                if(mx<ch.size())
                {
                    mx=ch.size();
                }
            }
        }
        set<string> :: iterator it;
        vector<string> ans;
        for(it=st.begin(); it!=st.end(); it++)
        {
            if((*it).size()==mx)
            {
                cnt++;
                ans.push_back(*it);
            }
        }
        cout<<cnt<<'\n';
        for(i=0;i<cnt;i++)
        {
            cout<<ans[i]<<'\n';
        }
    }
    return 0;
}
