#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ,i,a,j,x,y,m;
    long long sum =0;
    map<string,int> mp;
    string ch,arr;
    scanf("%d %d",&n,&m);
    getchar();
    for(i=1;i<=n;i++)
    {
        cin>>ch>>x;
        mp[ch]=x;
    }
    for(i=1;i<=m;i++)
    {
        sum =0;
        while(cin>>arr)
        {
            if(arr[0]=='.')
                break;
            sum += mp[arr];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
