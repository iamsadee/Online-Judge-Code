#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ch,ar;
    while(getline(cin,ch))
    {
        getline(cin,ar);
        map<char , int> mp[2];
        set<char> st;
        set<char> :: iterator it;
        int x=ch.length();
        for(int i=0;i<x;i++)
        {
            if(ch[i]>='a' && ch[i]<='z')
            {
                mp[0][ch[i]] +=1;
            }
        }
        x=ar.length();
        for(int i=0;i<x;i++)
        {
            if(ar[i]>='a' && ar[i]<='z')
            {
                mp[1][ar[i]] += 1;
                if(mp[0][ar[i]]>0)
                {
                    st.insert(ar[i]);
                }
            }
        }
        for(it=st.begin();it!=st.end();it++)
        {
            x=min(mp[0][*it],mp[1][*it]);
            for(int i=1;i<=x;i++)
            {
                printf("%c",*it);
            }
        }
        printf("\n");
    }
    return 0;
}
