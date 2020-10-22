#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,i;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        int arr[1005];
        vector<int> ans;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]!=0)
            {
                ans.push_back(arr[i]);
            }
        }
        if(ans.size()==0)
        {
            printf("0\n");
        }
        else
        {
            for(i=0;i<ans.size();i++)
            {
                printf("%d",ans[i]);
                if(i==ans.size()-1)
                {
                    printf("\n");
                }
                else printf(" ");
            }
        }
    }
    return 0;
}
