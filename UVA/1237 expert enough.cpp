#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    int t,i,j,k,q;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        ll l[10005],r[10005];
        scanf("%d",&n);
        string name[10005];
        ll x,y;
        getchar();
        for(j=0;j<n;j++)
        {
            cin>>name[j]>>l[j]>>r[j];
        }
        scanf("%d",&q);
        for(j=1;j<=q;j++)
        {
            scanf("%lld",&x);
            int ans =-1,chk=0;
            for(k=0;k<n && chk<=1;k++)
            {
                if(l[k]<=x && x<=r[k])
                {
                    ans=k;
                    chk++;
                }
                if(chk==2)
                    break;
            }
            if(chk==2 || ans==-1)
            {
                printf("UNDETERMINED\n");
            }
            else cout<<name[ans]<<endl;
        }
        if(i!=t)
            cout<<endl;
    }
    return 0;
}
