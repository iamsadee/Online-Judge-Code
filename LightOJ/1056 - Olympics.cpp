#include<bits/stdc++.h>
using namespace std;
double binary(int x,int y)
{
    double low ,high,mid,ans,ab,bd,r,a,s,p;
    ans=0;
    low=0;
    high = 401;
    while(abs(low-high)>=0.0000000001)
    {
        mid=(low+high)/2.0;
        ab=(mid*y)/(x*1.0);
        bd = sqrt((mid*mid)+(ab*ab));
        r=(bd/2.0);
        a=acos(((r*r)+(r*r)-(ab*ab))/(2*r*r*1.0));
        s=r*a;
        p=2*s+2*mid;
        if(p<=400)
        {
            ans=mid;
            low=mid;
        }
        else{high =mid;}
    }
    return ans;
}
int main()
{
    int i,t,j,x,y;
    char ch;
    double ans,ans_1;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %c %d",&x,&ch,&y);
        ans = binary(x,y);
        ans_1=(ans*y)/(x*1.0);
        printf("Case %d: %.10lf %0.10lf\n",i,ans,ans_1);
    }
    return 0;
}
