#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b,i,j,k,X,Y,Z;
    while(scanf("%d %d",&n,&b)==2)
    {
        vector<int> reserve;
        if(n==0 && b==0)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&X);
            reserve.push_back(X);
        }
        for(i=0;i<b;i++)
        {
            scanf("%d%d%d",&X,&Y,&Z);
            reserve[X-1] -= Z;
            reserve[Y-1] += Z;
        }
        int a=0;
        for(i=0;i<n;i++)
        {
            if(reserve[i]<0)
            {
                a=1;
                break;
            }
        }
        if(a==1)
            printf("N\n");
        else printf("S\n");
    }
    return 0;
}
