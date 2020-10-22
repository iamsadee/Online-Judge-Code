#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,x,y,a,b;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        scanf("%d %d",&x,&y);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            if(a-x>0 && b-y>0)
                printf("NE\n");
            else if(a-x>0 && b-y<0)
                printf("SE\n");
            else if(a-x<0 && b-y<0)
                printf("SO\n");
            else if(a-x<0 && b-y>0)
                printf("NO\n");
            else if(a-x==0 || b-y==0)
                printf("divisa\n");
        }
    }
    return 0;
}
