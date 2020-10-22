#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,a;
    char temp='a';
    map<long long int,long long int> mp;
    map<long long int,bool> st;
    vector<long long> arr;
    i=0;
    while(scanf("%lld%c",&a,&temp)==2)
    {
        if(st[a]==0)
        {
            st[a]=1;
            arr.push_back(a);
            i++;
        }
        mp[a] +=1;
        if(temp=='\n')
            break;
    }
    for(j=0;j<i;j++)
    {
        a=arr[j];
        printf("%lld %lld\n",arr[j],mp[a]);
    }
    return 0;
}
