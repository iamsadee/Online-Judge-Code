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
        int m,c,k,x;
        cin>>m>>c;
        vector<int> arr[22];
        int mx=0;
        int mn=0;
        for(int j=1;j<=c;j++)
        {
            cin>>k;
            mn=max(mn,k);
            for(int l=1;l<=k;l++)
            {
                cin>>x;
                arr[j].push_back(x);
            }
            sort(arr[j].begin(),arr[j].end());
            mx += arr[j][0];
        }
        if(mx>m)
        {
            cout<<"no solution"<<'\n';
        }
        else
        {
            int j,l;
            for(j=1;j<mn;j++)
            {
                for(l=1;l<=c;l++)
                {
                    if(j<arr[l].size())
                    {
                        mx += arr[l][j];
                        if(mx-arr[l][j-1]<=m)
                        {
                            mx=mx-arr[l][j-1];
                        }
                        else mx -= arr[l][j];
                    }
                }
            }
            cout<<mx<<'\n';
        }
    }
    return 0;
}
