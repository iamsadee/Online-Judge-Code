#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    gcd(y,x%y);
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    vector<string> arr;
    arr.push_back("Saturday");
    arr.push_back("Sunday");
    arr.push_back("Monday");
    arr.push_back("Tuesday");
    arr.push_back("Wednesday");
    arr.push_back("Thursday");
    arr.push_back("Friday");
    for(i=1;i<=t;i++)
    {
        int m,d;
        scanf("%d %d",&m,&d);
        int cnt=0;
        for(j=1;j<m;j++)
        {
            if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)
            {
                cnt += 31;
            }
            else if(j==2)
            {
                cnt += 28;
            }
            else cnt+=30;
        }
        cnt += d;
        cnt = cnt%7;
        if(cnt==0)
        {
            cnt =7;
        }
        cout<<arr[cnt-1]<<endl;
    }
    return 0;
}
