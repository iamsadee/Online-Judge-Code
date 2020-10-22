#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    gcd(y,x%y);
}
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        getchar();
        string ch;
        vector<string> arr,ans;
        for(j=0;j<n;j++)
        {
            cin>>ch;
            arr.push_back(ch);
        }
        sort(arr.begin(),arr.end());
        ll cnt=arr[0].size();
        //cout<<cnt<<endl;
        ans.push_back(arr[0]);
        for(j=0;j<(n-1);j++)
        {
            int l=0,m=0,k=j+1,o=arr[j].size();
            ans.push_back(arr[j+1]);
            string ab=arr[j+1];
            if(arr[j][l]==arr[k][m])
            {
                while(m<ab.size())
                {

                    if(l>o)
                    {
                        l=0;
                    }
                    if(arr[k][m]==arr[j][l])
                    {
                        l++;
                    }
                    else if(arr[k][m]!=arr[j][l])
                    {
                        //arr[j][l]=arr[k][m];
                        cnt += (ab.size()-(m));
                        break;
                    }
                    m++;
                }
                //cout<<cnt<<endl;
            }
            else
            {
                cnt += ab.size();
                //cout<<cnt<<endl;
            }
        }
        cout<<cnt<<endl;
        for(j=0;j<ans.size();j++)
        {
            cout<<ans[j]<<endl;
        }
    }
    return 0;
}
