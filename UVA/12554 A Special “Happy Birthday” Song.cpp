#include<bits/stdc++.h>
using namespace std;
int main()
{
    string wish[17],name[101];
    int n;
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
    {
        cin>>name[i];
        //cout<<name[i]<<endl;
    }
    wish[1]="Happy";
    wish[2]="birthday";
    wish[3]="to";
    wish[4]="you";
    wish[5]="Happy";
    wish[6]="birthday";
    wish[7]="to";
    wish[8]="you";
    wish[9]="Happy";
    wish[10]="birthday";
    wish[11]="to";
    wish[12]="Rujia";
    wish[13]="Happy";
    wish[14]="birthday";
    wish[15]="to";
    wish[16]="you";
    int x=0,y=1,z=1;
    while(x<n || y<=16)
    {
        if(z>n)
        {
            z=1;
        }
        if(y>16)
        {
            y=1;
        }
        cout<<name[z]<<": "<<wish[y]<<endl;
        x++;
        z++;
        y++;
    }
    return 0;
}
