#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ch;
    char chh;
    int t,i,x,arr[21],j,k;
    unsigned long long ans,sum;
    scanf("%d",&t);
    getchar();
    for(j=1;j<=t;j++)
    {
        ans=1;
        getline(cin,ch);
        x=ch.length();
        map<char,int> mp;
        set<char> st;
        set<char> :: iterator it;
        for(i=0;i<x;i++)
        {
            if(mp[ch[i]]==0)
            {
                st.insert(ch[i]);
            }
            mp[ch[i]] += 1;
        }
        for(i=1;i<=x;i++)
        {
            ans = ans*i ;
        }
        sum =1;
        for(it=st.begin();it!=st.end();it++)
        {
            k=mp[*it];
            for(i=1;i<=k;i++)
            {
                sum = sum *i;
            }
        }
        ans = ans/sum;
        printf("Data set %d: %llu\n",j,ans);
    }
    return 0;
}
