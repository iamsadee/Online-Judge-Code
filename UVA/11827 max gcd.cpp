#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(y==0) return x;
    gcd(y,x%y);
}
int main()
{
    string ch;
    int t,i,j,x,k,l;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        vector<int> arr;
        getline(cin,ch);
        istringstream ss(ch);
        j=0;
        while(ss>>x)
        {
            arr.push_back(x);
            j++;
        }
        int mx=0;
        for(k=0;k<j;k++)
        {
            for(l=0;l<j;l++)
            {
                if(k!=l)
                {
                    x=gcd(arr[k],arr[l]);
                    if(mx<x)
                    {
                        mx=x;
                    }
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
