#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> a,b;
int dp[105][105];
int n,m;
int lcs(int i,int j)
{
    if(i>=n || j>=m)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans;
    //cout<<n<<" "<<m<<endl;
    if(a[i]==b[j])
    {

        ans = 1+lcs(i+1,j+1);
    }
    else
    {
        ans=max(lcs(i+1,j),lcs(i,j+1));
    }
    return dp[i][j]=ans;
}
vector<string> ans;
void print(int i,int j)
{
    if(i>=n || j>=m)
        return;
    if(a[i]==b[j])
    {
        ans.push_back(a[i]);
        print(i+1,j+1);
    }
    else
    {
        int x=dp[i+1][j];
        int y=dp[i][j+1];
        if(x>=y)
        {
            print(i+1,j);
        }
        else print(i,j+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string ch;
    while(getline(cin,ch))
    {

        memset(dp,-1,sizeof dp);
        a.clear();
        b.clear();
        stringstream ss(ch);
        string word;
        while(ss>>word)
        {
            a.push_back(word);
        }
        if(ch!="#")
        {
            while(getline(cin,ch))
            {
                if(ch=="#")
                    break;
                stringstream s(ch);
                string wo;
                while(s>>wo)
                {
                    a.push_back(wo);
                }
            }
        }
        while(getline(cin,ch))
        {
            if(ch=="#")
                break;
            stringstream s(ch);
            string wo;
            while(s>>wo)
            {
                b.push_back(wo);
            }
        }
        n=a.size();
        m=b.size();
        //cout<<n<<" "<<m<<endl;
        ans.clear();
        int ans1=lcs(0,0);
        print(0,0);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
            if(i==ans.size()-1)
                cout<<"\n";
            else cout<<" ";
        }

    }
    return 0;
}
