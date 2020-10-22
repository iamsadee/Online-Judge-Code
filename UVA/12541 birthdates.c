#include<stdio.h>
int day(int d , int m ,int y,int mx)
{
    int D ,M ,dd,mm,yy, days ;
    D=31;
    M=12;
    dd = D-d ;
    if(D<d)
    {
        dd += 30 ;
        m += 1 ;
    }
    mm = M - m ;
    if(M<m)
    {
        mm += 12 ;
        y += 1;
    }
    yy = mx - y ;
    days = dd + mm*30 + yy*365 ;
    return days ;
}
int main()
{
    int n , i , d[101],m[101],y[101],j,k,mx,din[101];
    char str[101][16];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s%d%d%d",str[i],&d[i],&m[i],&y[i]);
    }
    mx = 0;
    for(i=1;i<=n;i++)
    {
        if(mx<=y[i])
        {
            mx = y[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        din[i] = day(d[i],m[i],y[i],mx);
    }
    mx = 0 ;
    for(i=1;i<=n;i++)
    {
        if(mx<=din[i])
        {
            mx = din[i];
            k = i ;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(mx>=din[i])
        {
            mx = din[i];
            j = i ;
        }
    }
    printf("%s\n%s\n",str[j],str[k]);
    return 0;
}
