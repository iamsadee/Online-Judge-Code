#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//bool dp[100][100];
int main()
{

    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        //ll one=0,two=0;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            sum=sum^x;
        }
        if(sum>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
