#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j,n;
    cin>>t;
    //cin.ignore();
    for(i=1;i<=t;i++)
    {
        cin>>n;
        cin.ignore();
        string a,b;
        cin>>a>>b;
        int cnt=0;
        for(j=0;j<n;j++)
        {
            int aa=a[j]-'0';
            int bb=b[j]-'0';
            int x=abs(aa-bb);
            int y=(min(aa,bb)+1)+9-(max(aa,bb));
            cnt += min(x,y);
        }
        cout<<"Case "<<i<<": "<<cnt<<'\n';
    }
    return 0;
}
