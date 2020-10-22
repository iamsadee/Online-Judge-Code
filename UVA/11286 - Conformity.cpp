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
        int i,j;
        if(n==0)
            break;
            int x;
        vector<int> arr[10005];
        map<vector<int>,int> mp;
        map<vector<int>,int> ::iterator it;
        int mx=0;
        for(i=1;i<=n;i++)
        {
           for(j=1;j<=5;j++)
           {
               cin>>x;
               arr[i].push_back(x);
           }
           sort(arr[i].begin(),arr[i].end());
           mp[arr[i]] +=1;
           mx=max(mx,mp[arr[i]]);
        }
        int cnt=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if((*it).second==mx)
            {
                cnt += (*it).second;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
