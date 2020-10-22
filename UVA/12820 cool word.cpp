#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,x,y,n,arr[100],k;
    string ch[10001];
    char a;
    k=1;
    while(scanf("%d",&t)==1){
    getchar();
    y=0;
    for(i=1;i<=t;i++)
    {
        map<char,int> mp;
        set<char> st;
        set<char>::iterator it;
        getline(cin,ch[i]);
        x=ch[i].length();
        for(j=0;j<x;j++)
        {
            a=ch[i][j];
            if(mp[a]==0)
            {
                st.insert(a);
            }
            mp[a] +=1;
        }
        memset(arr,0,sizeof arr);
        x=0;
        for(it=st.begin();it!=st.end();it++)
        {
            n=mp[*it];
            if(arr[n]==0)
            {
                arr[n]=1;
            }
            else if(arr[n]!=0)
            {
                x=1;
                break;
            }
        }
        if(x==0 && st.size()>1)
        {
            y++;
        }
    }
    printf("Case %d: %d\n",k++,y);
    }
    return 0;
}
