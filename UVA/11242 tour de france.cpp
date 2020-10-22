#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    int f,r;
    while(scanf("%d",&f)==1)
    {
        if(f==0)
            break;
        scanf("%d",&r);
        int F[20],R[20];
        for(int i=0;i<f;i++)
        {
            scanf("%d",&F[i]);
        }
        for(int i=0;i<r;i++)
        {
            scanf("%d",&R[i]);
        }
        vector<double> ans;
        int i,j;
        double x;
        for(i=0;i<r;i++)
        {
            for(j=0;j<f;j++)
            {
                x=(R[i]*1.0)/(F[j]*1.0);
                ans.push_back(x);
            }
        }
        sort(ans.begin(),ans.end());
        double mx=0;
        for(i=0;i<ans.size()-1;i++)
        {
            x=(ans[i+1]*1.0)/(ans[i]*1.0);
            mx=max(mx,x);
        }
        printf("%0.2lf\n",mx);
    }
    return 0;
}
