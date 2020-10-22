#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        int m;
        cin>>m;
        printf("Case %d:\n",i);
        for(int j=0;j<m;j++)
        {
            int c,d;
            cin>>c>>d;
            if(a<=c && c<=x && b<=d && d<=y)
            {
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
    }
    return 0;
}

