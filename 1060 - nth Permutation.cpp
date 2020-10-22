#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int n;
int cnt[200];
ll pre[22];
void fac()
{
    pre[0]=1;
    for(ll i=1; i<=20; i++)
    {
        pre[i]=pre[i-1]*i;
    }
}
ll k;
string ans;
void path(int pos)
{
    if(pos>n)
        return;
    for(char i='a'; i<='z'; i++)
    {
        if(cnt[i]>0)
        {
            ll req=pre[n-(pos)];
            for(int j='a'; j<='z'; j++)
            {
                if(cnt[j]>0)
                {
                    if(i==j)
                    {
                        req=req/(pre[cnt[j]-1]);
                    }
                    else
                    {
                        req=req/(pre[cnt[j]]);
                    }
                }
            }
            if(k>req)
            {
                k-=req;
            }
            else
            {
                ans.push_back(i);
                cnt[i]--;
                path(pos+1);
                break;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fac();
    int t;
    cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>a>>k;
        n=a.size();
        sort(a.begin(),a.end());
        memset(cnt,0,sizeof cnt);
        for(int i=0; i<n; i++)
        {
            cnt[a[i]]++;
        }
        ans.clear();
        ll req=pre[n];
        for(char a='a'; a<='z'; a++)
        {
            req=req/pre[cnt[a]];
        }
        //cout<<req<<endl;
        cout<<"Case "<<ks<<": ";
        if(k>req)
        {
            cout<<"Impossible\n";
        }
        else
        {
            path(1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
