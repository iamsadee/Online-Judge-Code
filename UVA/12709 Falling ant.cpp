#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,L[101],W[101],H[101],mx,ans[101];
    while(scanf("%d",&t)==1)
    {
        if(t==0)
            break;
            mx=0;
        for(i=0;i<t;i++)
        {
            scanf("%d %d %d",&L[i],&W[i],&H[i]);
            if(H[i]>mx)
            {
                mx=H[i];
            }
        }
        j=0;
        for(i=0;i<t;i++)
        {
            if(H[i]==mx)
            {
                ans[j] = L[i]*W[i]*H[i];
                j++;
            }
        }
        sort(ans,ans+j,greater<int>());
        printf("%d\n",ans[0]);
    }
    return 0;
}
