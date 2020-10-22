#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k=0;
    while(cin>>n)
    {
        if(k!=0)
        {
            cout<<'\n';
        }
        k++;
        cin.ignore();
        string ch[20],a,b;
        int x,y;
        for(i=1;i<=n;i++)
        {
            cin>>ch[i];
        }
        map<string,int> mp;
        for(i=1;i<=n;i++)
        {
            cin>>a;
            //cout<<'a'<<' '<<a<<endl;
            cin>>x;
            //cout<<x<<endl;
            cin>>y;
            for(j=1;j<=y;j++)
            {
                cin>>b;
                //cout<<b<<endl;
                mp[b] += (x/y);
                mp[a] -= (x/y);
            }
        }
        for(i=1;i<=n;i++)
        {
            cout<<ch[i]<<' '<<mp[ch[i]]<<'\n';
        }
    }
    return 0;
}
