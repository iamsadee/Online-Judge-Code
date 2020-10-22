#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int h1,h2,h3,h4,m1,m2,m3,m4;
        char a;
        cin>>h1>>a>>m1;
        cin>>h2>>a>>m2;
        cin>>h3>>a>>m3;
        cin>>h4>>a>>m4;
        int chk=0;
        double H1=h1+(m1/100.0);
        double H2=h2+(m2/100.0);
        double H3=h3+(m3/100.0);
        double H4=h4+(m4/100.0);
        if(H1<=H3 && H3<=H2)
        {
            chk=1;
        }
        else if(H1<=H4 && H4<=H2)
        {
            chk=1;
        }
        else if(H3<=H1 && H1<=H4)
        {
            chk=1;
        }
        else if(H3<=H2 && H2<=H4)
        {
            chk=1;
        }
        if(chk)
        {
            cout<<"Case "<<i<<": "<<"Mrs Meeting"<<'\n';
        }
        else cout<<"Case "<<i<<": "<<"Hits Meeting"<<'\n';
    }
    return 0;
}
