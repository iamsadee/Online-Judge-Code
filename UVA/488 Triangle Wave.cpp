#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,y,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        for(j=1;j<=y;j++)
        {
            for(k=1;k<=x;k++)
            {
                for(l=1;l<=k;l++)
                {
                    printf("%d",k);
                }
                printf("\n");
            }
            for(k=x-1;k>=1;k--)
            {
                for(l=1;l<=k;l++)
                {
                    printf("%d",k);
                }
                printf("\n");
            }
            if(j!=y)
                printf("\n");
        }
        if(i!=n)
            printf("\n");
    }
    return 0;
}
