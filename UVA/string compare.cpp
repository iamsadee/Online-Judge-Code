#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a="102";
    string b="23";
    if(!(a<b))
        cout<<a<<endl;
    else if(!(b>a))
        cout<<b<<endl;
    else if(a==b) cout<<"Equal"<<endl;
    return 0;
}
