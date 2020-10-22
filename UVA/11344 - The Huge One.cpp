#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int remainder(string ch,int y)
{
    int i,j=ch.size(),x;
    x=0;
    for(i=0;i<j;i++)
    {
        x = x*10 + (ch[i]-'0');
        x=x%y;
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i,j,k;
    cin.ignore();
    for(i=1;i<=t;i++)
    {
        string ch;
        cin>>ch;
        //cout<<ch<<endl;
        int n;
        int arr[14];
        cin>>n;
        for(j=1;j<=n;j++)
        {
            cin>>arr[j];
        }
        int chk=0;
        for(j=1;j<=n;j++)
        {
            int res=remainder(ch,arr[j]);
            if(res!=0)
            {
                chk=1;
                break;
            }
        }
        if(chk)
        {
            cout<<ch<<" - Simple."<<'\n';
        }
        else if(chk==0)
        {
            cout<<ch<<" - Wonderful."<<'\n';
        }
    }
    return 0;
}
