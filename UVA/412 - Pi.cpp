#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI acos(-1)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k;
    while(cin>>n)
    {
        if(n==0)
            break;
        int arr[55];
        for(i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        int cnt=0;
        int cnt_1=0;
        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                if(__gcd(arr[i],arr[j])==1)
                {
                    cnt++;
                }
                cnt_1++;

            }
        }
        if(cnt==0)
        {
            cout<<"No estimate for this data set."<<'\n';
        }
        else
        {
            double ans =sqrt((cnt_1*6)/(cnt*1.0));
            //cout<<ans<<endl;
            cout<<setprecision(6);
            cout<<fixed;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
