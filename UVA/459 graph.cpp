#include<bits/stdc++.h>
using namespace std;
map<char,char> par;
char khujo(char x)
{
    if(par[x]==x) return x;
    return par[x]=khujo(par[x]);
}
void makeset(char x,char y)
{
    par[khujo(y)]=khujo(x);
}
int main()
{
    int t,i,j;
    char ch;
    cin>>t;
    getchar();
    getchar();
    for(i=1;i<=t;i++)
    {
        par.clear();
        scanf("%c",&ch);
        getchar();
        for(char it='A';it<=ch;it++)
        {
            par[it]=it;
            //cout<<par[it]<<endl;
        }
        string a;
        while(getline(cin,a))
        {
            if(a.size()==0) break;
            //cout<<a[0]<<' '<<a[1]<<endl;
            makeset(a[0],a[1]);
        }
        set<char> st;
        for(char it='A';it<=ch;it++)
        {
            int r=khujo(it);
            st.insert(r);
        }
        printf("%d\n",st.size());
        if(i!=t)
            cout<<endl;
        st.clear();
    }
    return 0;
}
