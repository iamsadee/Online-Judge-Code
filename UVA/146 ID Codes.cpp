#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ch;
    while(cin>>ch)
    {
        if(ch=="#")
            break;
        string a=ch;
        int j=0;
        while(next_permutation(ch.begin(),ch.end()))
        {
            j++;
            if(j==1)
                break;
        }
        if(j==0)
        {
            cout<<"No Successor"<<'\n';
        }
        else
        {
            cout<<ch<<'\n';
        }
    }
    return 0;
}
