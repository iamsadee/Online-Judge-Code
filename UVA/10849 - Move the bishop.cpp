#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int T;
        ll n;
        cin>>T;
        cin>>n;
        ll x1,x2,y1,y2;
        for(int I=1;I<=T;I++)
        {
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2 && y1==y2)
            {
                cout<<"0"<<'\n';
            }
            else if((abs(x1-x2)%2)!=(abs(y1-y2)%2))
            {
                cout<<"no move"<<'\n';
            }
            else if(abs(x1-x2)==abs(y2-y1))
            {
                cout<<"1"<<'\n';
            }
            else cout<<"2"<<'\n';
        }
    }
    return 0;
}
