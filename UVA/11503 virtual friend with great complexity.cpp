#include<bits/stdc++.h>
using namespace std;
int arr[100005],par[100005];
int khujo(int x)
{
    if(par[x]==x) return x;
    return par[x]=khujo(par[x]);
}
void makeset(int x,int y)
{
    int u,v;
    u=khujo(x);
    v=khujo(y);
    if(u!=v){
            arr[khujo(par[u])] += arr[v];
            par[khujo(par[v])]=khujo(par[u]);
    }
}
int main()
{
    int t,i,j,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        getchar();
        map<int,string> mp;
        map<string,int> mo;
        map<string,bool> st;
        for(j=0;j<=100000;j++)
        {
            arr[j]=1;
        }
        int k=1;
        for(j=1;j<=n;j++)
        {
            string a,b;
            cin>>a>>b;
            if(st[a]==0)
            {
                mp[k++]=a;
                st[a]=1;
                mo[a]=k-1;
                par[k-1]=k-1;
            }
            if(st[b]==0)
            {
                mp[k++]=b;
                mo[b]=k-1;
                st[b]=1;
                par[k-1]=k-1;
            }
            int chk=0;
            //cout<<par[a]<<' '<<par[b]<<endl;
            //cout<<arr[a]<<' '<<arr[b]<<endl;
            /*if(arr[par[a]]<arr[par[b]])
            {
                swap(a,b);
            }*/
            //cout<<a<<b<<endl;
            //string c="Sadee";
            /*if(par[a]!=par[b])
            {
                chk=1;
                c=par[b];
            }*/
            makeset(mo[a],mo[b]);
            //cout<<arr[par[a]]<<endl;
            printf("%d\n",arr[par[mo[a]]]);
        }
    }
    return 0;
}
