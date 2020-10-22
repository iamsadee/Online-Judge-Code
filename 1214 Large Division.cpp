#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool div(string ch,ll x)
{
    ll y=0;
    int i;
    int rem;
    if(ch[0]=='-')
    {
        i=1;
    }
    else i=0;
    while(i<ch.size())
    {
        y = y*10 + (ch[i]-'0');
        i++;
        y=y%x;
    }
    if(y==0)
        return 1;
    else return 0;


}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        getchar();
        ll z;
        string ch;
        cin>>ch;
        scanf("%lld",&z);
        bool ans=div(ch,z);
        if(ans==true)
        {
            printf("Case %d: divisible\n",i);
        }
        else printf("Case %d: not divisible\n",i);
    }

    return 0;
}


