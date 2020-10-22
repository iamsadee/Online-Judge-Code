#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    int i;
    getchar();
    for(i=1;i<=t;i++)
    {
        string a,b;
        cin>>a>>b;
        int ans=0;
        if(a=="JAN" || a=="MAR" || a=="MAY" ||a=="JUL" || a=="AUG" || a=="OCT" || a=="DEC")
        {
            ans += ((31/7)*2);
            if(b=="WED")
            {
                ans +=1;
            }
            else if(b=="THU")
            {
                ans +=2;
            }
            else if(b=="SAT")
            {
                ans += 1;
            }
            else if(b=="FRI")
            {
                ans += 2;
            }
        }
        else if(a=="FEB")
        {
            ans += ((28/7)*2);
        }
        else
        {
            ans += ((30/7)*2);
            if(b=="THU")
            {
                ans++;
            }
            else if(b=="SAT")
            {
                ans++;
            }
            else if(b=="FRI")
            {
                ans += 2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
