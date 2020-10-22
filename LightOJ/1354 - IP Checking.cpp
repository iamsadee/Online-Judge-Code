#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int ks=1;ks<=t;ks++)
    {
        int a[5];
        char ch;
        cin>>a[0]>>ch>>a[1]>>ch>>a[2]>>ch>>a[3];
        string s;
        cin>>s;
        string x[5];
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                cnt++;
            }
            else
            {
                x[cnt].push_back(s[i]);
            }
        }
        bool chk=0;
        for(int i=0;i<4;i++)
        {
            int num=0;
            reverse(x[i].begin(),x[i].end());
            for(int j=0;j<x[i].size();j++)
            {
                int z=x[i][j];
                if(x[i][j]=='1')
                {
                    num += (1<<j);
                }
            }
            if(num!=a[i])
            {
                chk=1;
                break;
            }
        }
        if(chk==1)
        {
            printf("Case %d: No\n",ks);
        }
        else printf("Case %d: Yes\n",ks);


    }
    return 0;
}
