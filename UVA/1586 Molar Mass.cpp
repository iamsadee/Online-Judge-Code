#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,k,x,y,j;
    string ch;
    double ans;
    scanf("%d",&t);
    getchar();
    for(j=1;j<=t;j++)
    {
        getline(cin,ch);
        ans=0;
        x=ch.length();
        for(i=0;i<x;i++)
        {
            if(ch[i]=='C')
            {
                if(ch[i+1]>='1' && ch[i+1]<='9' && (i+1)<x)
                {
                    if(ch[i+2]>='1' && ch[i+2]<='9' && (i+2)<x)
                    {
                        ans += (((ch[i+1]-'0')*10+(ch[i+2]-'0')) * 12.01) ;
                        i=i+2;
                    }
                    else
                    {
                        ans += (((ch[i+1]-'0')) * 12.01) ;
                        i=i+1;
                    }
                }
                else ans += 12.01;
            }
            else if(ch[i]=='O')
            {
                if(ch[i+1]>='1' && ch[i+1]<='9' && (i+1)<x)
                {
                    if(ch[i+2]>='1' && ch[i+2]<='9'&& (i+2)<x)
                    {
                        ans += (((ch[i+1]-'0')*10+(ch[i+2]-'0')) * 16.00) ;
                        i=i+2;
                    }
                    else
                    {
                        ans += (((ch[i+1]-'0')) * 16.00) ;
                        i=i+1;
                    }
                }
                else
                {
                    ans += 16;
                }
            }
            else if(ch[i]=='H')
            {
                if(ch[i+1]>='1' && ch[i+1]<='9'&& (i+1)<x)
                {
                    if(ch[i+2]>='1' && ch[i+2]<='9'&& (i+2)<x)
                    {
                        ans += ((ch[i+1]-'0')*10+(ch[i+2]-'0')) * 1.008 ;
                        i=i+2;
                    }
                    else
                    {
                        ans += ((ch[i+1]-'0')) * 1.008 ;
                        i=i+1;
                    }
                }
                else ans += 1.008;
            }
            else if(ch[i]=='N')
            {
                if(ch[i+1]>='1' && ch[i+1]<='9'&& (i+1)<x)
                {
                    if(ch[i+2]>='1' && ch[i+2]<='9'&& (i+2)<x)
                    {
                        ans += ((ch[i+1]-'0')*10+(ch[i+2]-'0')) * 14.01 ;
                        i=i+2;
                    }
                    else
                    {
                        ans += ((ch[i+1]-'0')) * 14.01 ;
                        i=i+1;
                    }
                }
                else ans += 14.01;
            }
        }
        printf("%0.3lf\n",ans);
    }
    return 0;
}
