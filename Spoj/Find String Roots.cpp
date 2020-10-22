#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
///KMP Failure function
int n;
int fail[100005];
int pre(string ch)
{
    n=ch.size();
    fail[0]=0;
    fail[1]=0;
    for(int i=2;i<=n;i++)
    {
        int j=fail[i-1];
        while(true)
        {
            if(ch[i-1]==ch[j])
            {
                fail[i]=j+1;
                break;
            }
            else if(j==0)
            {
                fail[i]=0;
                break;
            }
            j=fail[j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(fail[i]==0) cnt=i;
    }
    if(n%cnt==0) return n/cnt;
    else return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string ch;
    while(cin>>ch)
    {
        if(ch=="*")
            break;
        cout<<pre(ch)<<"\n";

    }
    return 0;
}
