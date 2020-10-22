#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,r,c,n,m,x,k;
    char ch[21][21];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d %d",&r,&c,&n,&m);
        getchar();
        map<char,int> mp;
        set<char> st;
        set<char>::iterator it;
        for(j=0;j<r;j++)
        {
            scanf("%s",ch[j]);
            for(k=0;k<c;k++)
            {
                if(mp[ch[j][k]]==0)
                {
                    st.insert(ch[j][k]);
                }
                mp[ch[j][k]] +=1;
            }
        }
        int mx=0;
        for(it=st.begin();it!=st.end();it++)
        {
            if(mx<mp[*it])
            {
                mx=mp[*it];
            }
        }
        x=0;
        for(it=st.begin();it!=st.end();it++)
        {
            if(mx==mp[*it])
            {
                x+= mp[*it];
            }
        }
        int sum = x*n + ((r*c)-x)*m;
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
