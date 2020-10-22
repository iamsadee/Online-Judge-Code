#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t , a,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&a);
        if(a%2==0)
        {
            printf("%d %d\n",a/2,a/2);
        }
        else printf("%d %d\n",a/2,(a/2)+1);
    }
    return 0;
}
