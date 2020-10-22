#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ab,ac,bc,x,low,high,mid,ae,de,ans,ans_2,s,ans_1;
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>ab>>ac>>bc>>x;
        low =0;
        high=ab;
        while(abs(low-high)>0.00000000001)
        {
            mid = (low+high)/2.0;
            ae = (mid*ac)/(ab*1.0);
            de= (mid*bc)/(ab*1.0);
            s=(mid+ae+de)/2.0;
            ans=sqrt(s*(s-mid)*(s-ae)*(s-de));
            s=(ab+bc+ac)/2.0;
            ans_2=sqrt(s*(s-ab)*(s-bc)*(s-ac));
            s=ans_2-ans;
            ans_1=ans/(s*1.0);
            if(ans_1>x)
            {
                high=mid;
            }
            else
            {
                low =mid;
            }
        }
        printf("Case %d: %0.10lf\n",i,mid);
    }
    return 0;
}
