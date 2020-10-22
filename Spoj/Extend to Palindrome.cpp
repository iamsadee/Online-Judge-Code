#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/// KMP
/// palindrome prefix match reverse # normal
int n;
int fail[200005];
string in;
void pre(string ch)
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
    ll cnt=fail[n];
    int op=in.size()-cnt;
    for(int i=op-1;i>=0;i--)
    {
        in += in[i];
    }
    cout<<in<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string ch;
    while(cin>>ch)
    {
        in=ch;
        string a;
        a=ch;
        reverse(a.begin(),a.end());
        a += "#";
        a +=ch;
        pre(a);


    }
    return 0;
}
