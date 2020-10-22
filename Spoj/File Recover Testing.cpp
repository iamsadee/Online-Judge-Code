#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/// KMP failure function match
int n;
int fail[1000005];
string in;
ll k;
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
    int cnt=fail[n];
    cnt=n-cnt;
    if(k<n)
    {
        return 0;
    }
    else
    {
        int ans=1;
        k -= n;
        ans += (k/cnt);
        return ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string ch;
    while(cin>>k>>ch)
    {
        if(k==-1 && ch=="*")
        {
            break;
        }
        cout<<pre(ch)<<endl;

    }
    return 0;
}
