#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 2*acos(0.0)
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int ans=n*m;
        int d=1;
        if(n==1 || m==1)
            printf("Case %d: %d\n",ks,ans);
        else if((n==2 && m%2==1) || (m==2 && n%2==1))
        {
            if(n==2)
            {
                ans=m+1;
            }
            else ans = n+1;
            printf("Case %d: %d\n",ks,ans);
        }
        else if(n==2 || m==2)
        {
            ans=((n*m)/4);
            if(ans%2==1)
            {
                ans=ans/2;
                ans++;
            }
            else ans=ans/2;
            ans = ans*4;
            printf("Case %d: %d\n",ks,ans);
        }
        else
        {
            if(ans%2==1)
            {
                ans=ans/2;
                ans++;
            }
            else ans=ans/2;
            printf("Case %d: %d\n",ks,ans);
        }
    }
    return 0;
}
