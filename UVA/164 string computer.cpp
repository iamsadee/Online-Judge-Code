#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,dp[30][30];
string a,b;
int fun(int i,int j)
{
    if(i==a.size())
    {
        return b.size()-j;
    }
    if(j==b.size())
    {
        return a.size()-i;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int res=0,res1,res2,res3;
    if(a[i]==b[j] )
    {
        res = (fun(i+1,j+1));
    }
    else{
    res1=1+fun(i+1,j);
    res3=1+fun(i+1,j+1);
    res2=1+fun(i,j+1);
    res = min(res1,res2);
    res = min(res,res3);
    }
    return dp[i][j]=res;
}
void path(int i,int j)
{
    if(i==a.size())
    {
        for(int k=j;k<b.size();k++)
        {
            printf("I%c",b[k]);
            if(k+1<=9)
            {
                printf("0%d",k+1);
            }
            else printf("%d",k+1);
        }
        return;
    }
    if(j==b.size())
    {
        for(int k=i;k<a.size();k++)
        {
            printf("D%c",a[k]);
            if(j+1<=9)
            {
                printf("0%d",j+1);
            }
            else printf("%d",j+1);
        }
        return ;
    }
    int res=dp[i][j];
    if(a[i]==b[j])
    {
        path(i+1,j+1);
    }
    else if(res==(1+fun(i+1,j)))
    {
        printf("D%c",a[i]);
        if((j+1)<=9)
            printf("0%d",j+1);
        else printf("%d",j+1);
        path(i+1,j);
    }
    else if(res==(1+fun(i,j+1)))
    {
        printf("I%c",b[j]);
        if(j+1<=9)
            printf("0%d",j+1);
        else printf("%d",j+1);
        path(i,j+1);
    }
    else if(res==(1+fun(i+1,j+1)))
    {
        printf("C%c",b[j]);
        if(j+1<=9)
            printf("0%d",j+1);
        else printf("%d",j+1);
        path(i+1,j+1);
    }
}
int main()
{
    while(cin>>a)
    {
        if(a=="#")
            break;
        cin>>b;
        memset(dp,-1,sizeof dp);
        int y=fun(0,0);
        path(0,0);
        printf("E\n");
    }
    return 0;
}
