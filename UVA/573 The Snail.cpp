#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,u,d,f;
    while(cin>>h>>u>>d>>f)
    {
        //cout<<h<<' '<<u<<' '<<d<<' '<<f<<endl;
        if(h==0)
            break;
        int chk=1;
        ll cnt=1;
        double baad=((f*1.0)/100.0)*u;
        double dis=u;
        double total = u;
        if(total>h)
        {
            chk=0;
        }
        if(total<=h)
        {
            total=u-d;
        }
        while(chk)
        {
            if(total<0)
            {
                break;
            }
            cnt++;
            dis -= baad;
            if(dis>=0)
            {
                total += dis;
            }
            if(total>h)
            {
                break;
            }
            total -= d;
            //cout<<total<<endl;
        }
        if(total>h)
        {
            cout<<"success on day "<<cnt<<'\n';
        }
        else
        {
            cout<<"failure on day "<<cnt<<'\n';
        }
    }
    return 0;
}
