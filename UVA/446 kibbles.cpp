#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,i,j;
    scanf("%d",&n);
    getchar();
    for(j=1;j<=n;j++)
    {
        string a,b,c,ans;
        cin>>a>>c>>b;
        string d,e;
        d.push_back('0');
        e.push_back('0');
        for(i=1;i<=(3-a.size());i++)
        {
            d+="0000";
        }
        for(i=1;i<=(3-b.size());i++)
        {
            e+=("0000");
        }
        for(i=0;i<a.size();i++)
        {
            if(a[i]=='0')
            {
                d+="0000";
            }
            else if(a[i]=='1')
            {
                d+=("0001");
            }
            else if(a[i]=='2')
            {
                d+="0010";
            }
            else if(a[i]=='3')
            {
                d+="0011";
            }
            else if(a[i]=='4')
            {
                d+="0100";
            }
            else if(a[i]=='5')
            {
                d+="0101";
            }
            else if(a[i]=='6')
            {
                d+="0110";
            }
            else if(a[i]=='7')
            {
                d+="0111";
            }
            else if(a[i]=='8')
            {
                d+="1000";
            }
            else if(a[i]=='9')
            {
                d+="1001";
            }
            else if(a[i]=='A')
            {
                d+="1010";
            }
            else if(a[i]=='B')
            {
                d+="1011";
            }
            else if(a[i]=='C')
            {
                d+="1100";
            }
            else if(a[i]=='D')
            {
                d+="1101";
            }
            else if(a[i]=='E')
            {
                d+="1110";
            }
            else if(a[i]=='F')
            {
                d+="1111";
            }
        }
        for(i=0;i<b.size();i++)
        {
            if(b[i]=='0')
            {
                e+="0000";
            }
            else if(b[i]=='1')
            {
                e+=("0001");
            }
            else if(b[i]=='2')
            {
                e+="0010";
            }
            else if(b[i]=='3')
            {
                e+="0011";
            }
            else if(b[i]=='4')
            {
                e+="0100";
            }
            else if(b[i]=='5')
            {
                e+="0101";
            }
            else if(b[i]=='6')
            {
                e+="0110";
            }
            else if(b[i]=='7')
            {
                e+="0111";
            }
            else if(b[i]=='8')
            {
                e+="1000";
            }
            else if(b[i]=='9')
            {
                e+="1001";
            }
            else if(b[i]=='A')
            {
                e+="1010";
            }
            else if(b[i]=='B')
            {
                e+="1011";
            }
            else if(b[i]=='C')
            {
                e+="1100";
            }
            else if(b[i]=='D')
            {
                e+="1101";
            }
            else if(b[i]=='E')
            {
                e+="1110";
            }
            else if(b[i]=='F')
            {
                e+="1111";
            }
        }
        double x=0,y=0,z,l=0;
        for(i=d.size()-1;i>=0;i--)
        {
            x+=((d[i]-'0')*(pow(2,l)));
            y+= ((e[i]-'0')*pow(2,l));
            l++;
        }
        //cout<<x<<' '<<y<<endl;
        if(c=="+")
        {
            z=(x+y);
        }
        else if(c=="-")
        {
            z=(x-y);
        }
        cout<<d<<' '<<c<<' '<<e<<" = "<<z<<endl;
    }
    return 0;
}
