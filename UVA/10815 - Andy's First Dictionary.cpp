#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ch;
    set<string> st;
    set<string>:: iterator it;
    int i,n;
    while(cin>>ch)
    {
        string a;
        n=ch.size();
        for(i=0; i<n; i++)
        {
            if(ch[i]>='A' && ch[i]<='Z')
            {
                a.push_back(tolower(ch[i]));
            }
            else if(ch[i]>='a' && ch[i]<='z')
            {
                a.push_back(ch[i]);
            }
            else
            {
                st.insert(a);
                a.clear();
            }
        }
        st.insert(a);
    }
    //n=st.size();
    i=0;
    for(it=st.begin(); it!=st.end(); it++)
    {
        if(i!=0)
        {
            cout<<(*it)<<'\n';
        }
        i++;
    }
    return 0;
}
