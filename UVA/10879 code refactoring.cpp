#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,i,j,t,y,k;
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld",&x);
        y=sqrt(x);
        vector<long long> arr;
        map<long long,bool> mp;
        j=0;
        for(i=2;i<=y;i++)
        {
            if(x%i==0)
            {
                if(x%(x/i)==0 && x!=(x/i))
                {
                    if(mp[i]==0 && mp[x/i]==0){
                    arr.push_back(x/i);
                    arr.push_back(i);
                    j++;
                    }
                }
            }
            if(j==2)
                break;
        }
        printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n",k,x,arr[0],arr[1],arr[2],arr[3]);
    }
    return 0;
}
