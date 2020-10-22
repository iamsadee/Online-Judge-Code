#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,mx,sum,x;
    string ch;
    while(getline(cin,ch))
    {
        istringstream ss(ch);
        mx=0;
        sum=0;
        while(ss>>x)
        {
            sum += x;
            if(mx<sum)
            {
                mx=sum;
            }
            if(sum<0)
            {
                sum =0;
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
