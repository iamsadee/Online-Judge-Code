#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ,i,a;
    while(scanf("%d",&n)==1)
    {
        queue<int> arr;
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            arr.push(i);
        }
        i=1;
        printf("Discarded cards:");
        while(arr.size()>1)
        {
            if(i%2==1)
            {
                a=arr.front();
                printf(" %d",a);
                arr.pop();
            }
            else if(i%2==0)
            {
                printf(",");
                a=arr.front();
                arr.push(a);
                arr.pop();
            }
            i++;
        }
        a=arr.front();
        printf("\n");
        printf("Remaining card: %d\n",a);
    }
    return 0;
}
