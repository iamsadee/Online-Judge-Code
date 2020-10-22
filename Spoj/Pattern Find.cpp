#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
///KMP pattern search
int n;
int fail[2000005];
void pre(string ch,int sz)
{
    n=ch.size();
    fail[0]=0;
    fail[1]=0;
    for(int i=2;i<=n;i++)
    {
        int j=fail[i-1];
        while(true)
        {
            if(ch[i-1]==ch[j])
            {
                fail[i]=j+1;
                break;
            }
            else if(j==0)
            {
                fail[i]=0;
                break;
            }
            j=fail[j];
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(fail[i]==sz)
        {
            ans.push_back(i-(2*sz));
        }
    }
    if(ans.size()==0) cout<<"Not Found\n";
    else
    {
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
        {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1;ks<=t;ks++)
    {
        if(ks!=1) cout<<"\n";
        string ch,pat;
        cin>>ch>>pat;
        pre(pat+"#"+ch,pat.size());
    }
    return 0;
}
