#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ch;
    int n,i,j;
    double ans;
    scanf("%d",&n);
    getchar();
    getchar();
    for(i=1;i<=n;i++)
    {
        map<string,int> mp;
        set<string> st;
        set<string>::iterator it;
        j=0;
        while(getline(cin,ch) && ch.length()>0)
        {
            if(mp[ch]==0)
            {
                st.insert(ch);
            }
            mp[ch] += 1;
            j++;
        }
        for(it=st.begin();it!=st.end();it++)
        {
            ans = (mp[*it]*1.0/j*1.0)*100.0;
            cout<<*it;
            printf(" %0.4lf\n",ans);
        }
        if(i!=n)
            printf("\n");
    }
    return 0;
}
