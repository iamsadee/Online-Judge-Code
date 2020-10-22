#include<bits/stdc++.h>
using namespace std;
string fib[5005];
bool chk(string a,string b)
{
    if(a.size()<b.size())
        return true;
    if(a.size()>b.size())
        return false;
    if(a.size()==b.size()){
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<b[i])
            return true;
        else if(a[i]>b[i]) return false;
    }
    }
    return false;
}
bool chk_1(string a,string b)
{
    if(a==b)
        return true;
    if(a.size()<b.size())
        return true;
    if(a.size()>b.size())
        return false;
    if(a.size()==b.size()){
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<b[i])
            return true;
        else if(a[i]>b[i]) return false;
    }
    }
    return true;
}
int binary(string a)
{
    int low=2;
    int high=5000,ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        //cout<<mid<<endl;
        if(chk(fib[mid],a))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
int binary_1(string a)
{
    int low=2;
    int high=5000,ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        //cout<<'2'<<' '<<mid<<endl;
        if(chk_1(fib[mid],a))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
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
    }
    for(int i=0;i<=5000;i++)
    {
        reverse(fib[i].begin(),fib[i].end());
    }
    string a,b;
    while(cin>>a)
    {
        cin>>b;
        //cout<<a<<' '<<b<<endl;
        if(a=="0" && b=="0")
            break;
        int r1=binary(a);
        int r2=binary_1(b);
        cout<<r2-r1<<endl;
    }
    return 0;
}
