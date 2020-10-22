#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ch;
    int x,y,n,i;
    double sum;
    cin>>n;
    getchar();
    for(i=1;i<=n;i++)
    {
        getline(cin,ch);
        if(ch.length()>4)
        {
            x=ch[4]-'0';
            y=ch[0]-'0';
        }
        else
        {
            x=0;
            y=ch[0]-'0';
        }
        sum = x*0.05 + y*0.5;
        cout<<"Case "<<i<<": "<<sum<<endl;
    }
    return 0;
}
