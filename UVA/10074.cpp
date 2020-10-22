#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[105][105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>arr[i][j];
            }
        }
        int ans=0;
        int tmp[105];
        int area=0;
        for(int i=1; i<=m; i++)
        {
            for(int k=1; k<=m; k++)
            {
                tmp[k]=0;
            }
            for(int j=i; j<=m; j++)
            {
                for(int k=1; k<=n; k++)
                {
                    tmp[k] += arr[k][j];
                }
                int sum=0;
                int left,right,up=1,dwn;
                for(int k=1; k<=n; k++)
                {
                    sum += tmp[k];
                    if(sum>0)
                    {
                        sum=0;
                        up=k+1;
                    }
                    if(ans==sum)
                    {
                        dwn=k;
                        int req=((j-i)+1)*((k-up)+1);
                        area=max(area,req);
                    }
                }
            }
        }
        cout<<area<<endl;
    }
    return 0;
}
