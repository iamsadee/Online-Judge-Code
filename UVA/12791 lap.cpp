#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int T , i , x , y ,j,c,d;
    while(scanf("%lld %lld",&x,&y)==2)
    {
        i=x;
        j=y;
        c=1;
        d=y%x;
        while(1)
        {
            x+=i;
            if(x<=y)
                break;
            else if(x>y)
            {
                y+=j;
            }
            c++;
        }
        printf("%lld\n",c+1);
    }
    return 0;
}
