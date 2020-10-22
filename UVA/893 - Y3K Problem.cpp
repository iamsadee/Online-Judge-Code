#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while(cin>>n)
    {
        ll m,da,y;
        int d;
        cin>>da>>m>>y;
        if(n==0 && da==0 && m==0 && y==0)
            break;
        int arr[13];
        for(int j=1; j<=12; j++)
        {
            if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)
            {
                arr[j]= 31;
            }
            else if(j==2)
            {
                arr[j]= 28;
            }
            else arr[j]=30;
        }
        int chk;
        if(m<=2)
        {
            chk=1;
        }
        else chk=0;
        while(1)
        {
            if(y%4==0 && m<=2 )
            {
                if(y%100==0 && y%400==0)
                {
                    d=366;
                }
                else if(y%100==0)
                {
                    d=365;
                }
                else d=366;
            }
            else if(m<=2) d=365;
            if((y+1)%4==0 &&  m>2 )
            {
                if((y+1)%100==0 && (y+1)%400==0)
                {
                    d=366;
                }
                else if((y+1)%100==0)
                {
                    d=365;
                }
                else d=366;
            }
            else if(m>2) d=365;

            if(n>=d)
            {
                n-=d;
                y++;
            }
            else break;
            chk=1;
        }
        int day=da,month=m;
        ll year=y;
        //cout<<n<<endl;
        for(int j=1; j<=n; j++)
        {
            if(year%4==0)
            {
                if(year%100==0 && year%400==0)
                {
                    arr[2]=29;
                }
                else if(year%100==0)
                {
                    arr[2]=28;
                }
                else arr[2]=29;
            }
            else arr[2]=28;
            if((day+1)<=arr[month])
            {
                day++;
            }
            else if(day==arr[month])
            {
                month++;
                day=1;
                if(month>12)
                {
                    month=1;
                    year++;
                }
            }
        }
        cout<<day<<' '<<month<<' '<<year<<'\n';
    }
    return 0;
}
