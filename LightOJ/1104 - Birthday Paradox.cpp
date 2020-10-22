#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int ks=1;
    while(t--)
    {
        int n;
        cin>>n;
        int res;
        double ans=1;
        for(int i=0;i<=n;i++)
        {
            ans=ans*((n-i)/(n*1.0));
            double req=1.0-ans;
            if(req>=.50000)
            {
                res=i;
                break;
            }
        }
        cout<<"Case "<<ks<<": "<<res<<endl;
        ks++;
    }
    return 0;
}
