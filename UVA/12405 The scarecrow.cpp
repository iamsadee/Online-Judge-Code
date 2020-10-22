#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k,x,n;
    char ch[100000];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int count=0;
        scanf("%d",&n);
        getchar();
        scanf("%s",ch);
        x=strlen(ch);
        for(j=0;j<x;j++)
        {
            if(ch[j]=='.')
            {
                j=j+2;
                count++;
            }
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}

