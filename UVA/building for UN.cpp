#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,pp=0;
    map<int,char> mp;
    char ch='A';
    for(int i=1; i<=26; i++)
    {
        mp[i]=ch;
        ch++;
    }
    ch='a';
    for(int i=27; i<=50; i++)
    {
        mp[i]=ch;
        ch++;
    }
    while(cin>>n)
    {
        if(pp)
            cout<<endl;
        pp++;
        cout<<3<<" "<<n<<" "<<n<<"\n";
        int cnt=1;
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                cout<<mp[cnt];

            }
            cout<<endl;
            cnt++;
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cnt=1;
            for(int j=1;j<=n;j++)
            {
                cout<<mp[cnt];
                cnt++;
            }
            cout<<endl;
        }
        cout<<endl;
        cnt=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<mp[cnt];
            }
            cnt++;
            cout<<endl;
        }

    }
    return 0;
}
