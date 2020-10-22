#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/// KMP failure function
int n;
int fail[1000005];
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
    }//int i=0;
    for(int j=2;j<=n;j++)
    {
        if(fail[j]>0 && j%(j-fail[j])==0)
        {
            cout<<j<<" "<<j/(j-fail[j])<<"\n";
        }
    }
    cout<<"\n";
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string ch;
    int t;
    cin>>t;
    int ks=0;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>ch;
        ks++;
        cout<<"Test case #"<<ks<<"\n";
        pre(ch);

    }
    return 0;
}
