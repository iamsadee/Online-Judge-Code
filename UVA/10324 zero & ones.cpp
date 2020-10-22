#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c,b;
    string ch;
    int i,j,x,y,n,k,l=1;
    while(getline(cin,ch) && ch.length()>0 )
    {
        map<int,int> mp;
        map<int,int> st;
        k=ch.length();
        x=0;
        y=0;
        for(i=0;i<k;i++)
        {
            if(ch[i]=='0')
            {
                x+=1;
                st[i] = x;
                mp[i]=y;
            }
            else if(ch[i]=='1')
            {
                y+=1;
                mp[i]=y;
                st[i]=x;
            }
        }
        scanf("%d",&n);
        printf("Case %d:\n",l++);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            if(ch[x]=='0')
            {
                if(mp[x]==mp[y])
                    printf("Yes\n");
                else printf("No\n");
            }
            else if(ch[x]=='1')
            {
                if(st[x]==st[y])
                    printf("Yes\n");
                else printf("No\n");
            }
        }
        getchar();
    }
    return 0;
}
