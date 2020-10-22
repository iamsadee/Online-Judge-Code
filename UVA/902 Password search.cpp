#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string ch;
    while(scanf("%d",&n)==1)
    {
        getchar();
        getline(cin,ch);
        //cout<<ch<<endl;
        int i,j;
        int mx=0;
        map<string,int> mp;
        string ans;
        for(i=0;i<ch.size();i++)
        {
            if(i+n>=ch.size())
                break;
            string a;
            for(j=0;j<n;j++)
            {
                a.push_back(ch[i+j]);
            }
            mp[a] +=1;
            if(mx<mp[a])
            {
                mx=mp[a];
                ans=a;
            }
        }
        //printf("%d \n",i);
        cout<<ans<<endl;
    }
    return 0;
}
