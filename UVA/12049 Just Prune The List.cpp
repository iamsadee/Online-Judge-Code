#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,arr[10000],ar[10000],n,m,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        map<int,int> mp;
        map<int,int> st;
        set<int> a;
        set<int>::iterator it;
        set<int> b;
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            if(mp[arr[j]]==0)
            {
                a.insert(arr[j]);
            }
            mp[arr[j]] += 1;
        }
        for(j=0;j<m;j++)
        {
            scanf("%d",&ar[j]);
            if(st[ar[j]]==0)
            {
                b.insert(ar[j]);
            }
            st[ar[j]] +=1;
        }
        x=0;
        for(it=a.begin();it!=a.end();it++)
        {
            x +=abs(mp[*it]-st[*it]);
            mp[*it]=0;
            st[*it]=0;
        }
        for(it=b.begin();it!=b.end();it++)
        {
            x +=abs(mp[*it]-st[*it]);
            mp[*it]=0;
            st[*it]=0;
        }
        printf("%d\n",x);
    }
    return 0;
}
