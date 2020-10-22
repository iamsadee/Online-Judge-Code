#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    string x[10];
    for(int i=1;i<=1e6;i++)
    {
        x[1].push_back('1');
        x[2].push_back('2');
        x[3].push_back('3');
        x[4].push_back('4');
        x[5].push_back('5');
        x[6].push_back('6');
        x[7].push_back('7');
        x[8].push_back('8');
        x[9].push_back('9');
    }
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        ll y,z;
        scanf("%lld %lld",&y,&z);
        int n=x[z].size();
        ll sum=0;
        int ans;
        for(int i=0;i<n;i++)
        {
           sum = (sum*10+(x[z][i]-'0'));
           if(sum%y==0)
           {
               ans =i+1;
               break;
           }
           if(sum>y)
           {
               sum=sum%y;
           }

        }
        printf("Case %d: %d\n",a,ans);
    }
    return 0;
}
