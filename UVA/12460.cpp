#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int par[30005];
int fnd(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    return par[x]=fnd(par[x]);
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    //cout.tie(NULL);
    for(int i=1;i<=30000;i++)
    {
        par[i]=i;
    }
    map<string,int> mp;
    //map<int,string> rev;
    int cnt=1;
    string ch;
    vector<string>arr;
    while(cin>>ch)
    {
        if(ch=="--")
            break;
        if(mp[ch]==0)
        {
            mp[ch]=cnt;
            cnt++;
        }
        arr.push_back(ch);
    }
    for(int i=0;i<arr.size();i++)
    {
        int sz=arr[i].size();
        for(int j=0;j<sz;j++)
        {
            string tmp=arr[i];
            for(char k='a';k<='z';k++)
            {
                if(arr[i][j]!=k)
                {
                    tmp[j]=k;
                    if(mp[tmp]!=0)
                    {
                        int u=fnd(mp[tmp]);
                        int v=fnd(mp[arr[i]]);
                        if(u!=v)
                        {
                            par[u]=v;
                        }
                    }
                }
            }
        }
    }
    string a,b;
    while(cin>>a>>b)
    {
        if(mp[a]!=0 && mp[b]!=0)
        {
            int u=fnd(mp[a]);
            int v=fnd(mp[b]);
            if(u==v)
            {
                printf("Yes\n");
            }
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}
