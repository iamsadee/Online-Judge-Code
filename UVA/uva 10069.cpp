#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string dp[10005][102];
int vis[10005][102];
string a,b;
int n,m;
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
    int carry = 0;
    for (int i=n1-1; i>=0; i--)
    {
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
string fun(int i,int j)
{

    if(i>=n)
    {
        if(j>=m)
        {
            return "1";
        }
        else return "0";
    }
    //cout<<i<<" "<<j<<endl;
    if(j>=m)
    {
        return "1";
    }
    if(vis[i][j]!=-1) return dp[i][j];
    string ret="0";
    //cout<<a[i]<<" "<<b[j]<<endl;
    if(a[i]==b[j])
    {
        ret = findSum(ret,fun(i+1,j+1));
    }
    ret =findSum(ret, fun(i+1,j));
    vis[i][j]=1;
    return dp[i][j]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,-1,sizeof vis);
        //cout<<dp[0][0]<<endl;
        cin>>a>>b;
        n=a.size();
        m=b.size();
        string ans=fun(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
