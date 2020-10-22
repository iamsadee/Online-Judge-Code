#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int ks=1;ks<=t;ks++)
    {
        int n,k;
        cin>>n>>k;
        if(n<k)
        {
            cout<<"Case "<<ks<<": 0"<<"\n";
        }
        else
        {
            int vis[35];
            int vis1[35];
            int vis2[35];
            int vis3[35];
            int vis4[35];
            memset(vis,0,sizeof vis);
            memset(vis1,0,sizeof vis1);
            memset(vis2,0,sizeof vis2);
            memset(vis3,0,sizeof vis3);
            for(int i=1;i<=n;i++)
            {
                vis[i]++;
                vis2[i]++;
            }
            for(int i=1;i<=(n-k);i++)
            {
                vis1[i]++;
                vis3[i]++;
            }
            for(int i=1;i<=k;i++)
            {
                vis3[i]++;
            }
            ll res1=1,res2=1,res3=1;
            for(int i=1;i<=n;i++)
            {
                if(vis[i]>0 && vis1[i]==0)
                {
                    res1=res1*(ll)i;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(vis2[i]>0 && vis3[i]==0)
                {
                    res2=res2*(ll)i;
                }
                if(vis3[i]==2)
                {
                    res3=res3*(ll)i;
                }
            }
            res2=res2/res3;
            ll res=res1*res2;
            cout<<"Case "<<ks<<": "<<res<<"\n";
        }
    }
    return 0;
}
