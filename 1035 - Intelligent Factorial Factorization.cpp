#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> prime;
void pri()
{
    for(int i=2; i<=100; i++)
    {
        bool chk=0;
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
            {
                chk=1;
                break;
            }
        }
        if(chk==0) prime.push_back(i);
    }
}
struct A
{
    int p,num;
};
vector<A> ans;
void factFactorize ( int n )
{
    for ( int i = 0; i < prime.size() && prime[i] <= n; i++ )
    {
        int x = n;
        int freq = 0;
        while ( x / prime[i] )
        {
            freq += x / prime[i];
            x = x / prime[i];
        }
        A a;
        a.p=prime[i];
        a.num=freq;
        ans.push_back(a);
    }
}
int main()
{
    int n;
    int t;
    pri();
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int n;
        scanf("%d",&n);
        ans.clear();
        factFactorize(n);
        printf("Case %d: %d = ",i,n);
        //cout<<ans.size()<<endl;
        for(int j=0;j<ans.size();j++)
        {
            printf("%d (%d)",ans[j].p,ans[j].num);
            if(j==ans.size()-1)
            {
                printf("\n");
            }
            else
                printf(" * ");
        }
    }
    return 0;
}
