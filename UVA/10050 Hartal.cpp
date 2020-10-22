#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,x,y,j,k,b,t;
    set<int> hat;
    set<int>::iterator it;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        scanf("%d",&b);
        for(j=1;j<=b;j++)
        {
            scanf("%d",&a);
            for(k=a;k<=n;k+=a)
            {
                if(k%7!=6 && k%7!=0)
                {
                    hat.insert(k);
                }
            }
        }
        a=hat.size();
        printf("%d\n",a);
        hat.clear();
    }
    return 0;
}
