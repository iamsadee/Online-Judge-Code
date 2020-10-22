#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ch,ar,arr,input;
    map<string,string> mp;
    int j;
    while(getline(cin,ch) && ch.length()>0)
    {
        stringstream ss ;
        ss<<ch;
        j=0;
        while(ss>>ar)
        {
            if(j==0)
            {
                arr=ar;
                j++;
            }
            else
            {
                mp[ar]=arr;
            }
        }
    }
    while(getline(cin,input))
    {
        if(mp[input]=="")
            printf("eh\n");
        else cout<<mp[input]<<endl;
    }
    return 0;
}
