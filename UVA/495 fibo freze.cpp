#include<bits/stdc++.h>
using namespace std;
int main()
{
    string fib[5005];
    int n;
    fib[0].push_back('0');
    fib[1].push_back('1');
    for(int i=2;i<=5000;i++)
    {
        int x=fib[i-1].size();
        int y=fib[i-2].size();
        //cout<<x<<' '<<y<<endl;
        int k=0;
        int a,c=0;
        int j;
        if(x>=y)
        {
            for(j=0;j<y;j++)
            {
                //if(i==8) cout<<fib[i-1][j]<<' '<<fib[i-2][j]<<endl;
                a=(fib[i-1][j]-'0')+(fib[i-2][j]-'0')+c;
                //if(i==8) cout<<a<<' ';
                //getchar();
                if(a<=9)
                {
                    fib[i].push_back(a+'0');
                    c=0;
                }
                else
                {
                    fib[i].push_back((a%10)+'0');
                    c=a/10;
                }
            }
        }
        for(j=y;j<x;j++)
        {
            a=(fib[i-1][j]-'0')+c;
            //if(i==8) cout<<fib[i-1][j]<<' '<<endl;
            //if(i==8)
                //cout<<a<<' ';
            if(a<=9)
            {
                fib[i].push_back(a+'0');
                c=0;
            }
            else
            {
                fib[i].push_back((a%10)+'0');
                c=a/10;
            }
        }
        if(c!=0)
        {
            fib[i].push_back(c+'0');
        }
        //cout<<endl;
        //reverse(fib[i].begin(),fib[i].end());
    }
    for(int i=0;i<=5000;i++)
    {
        reverse(fib[i].begin(),fib[i].end());
    }
    while(scanf("%d",&n)==1)
    {
        printf("The Fibonacci number for %d is ",n);
        cout<<fib[n]<<endl;
    }
    return 0;
}
