#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1000],n,i,x,y,j,ar[11];
    map<int,string> mp;
    string ch;
    i=0;
    y=0;
    memset(ar,0,sizeof ar);
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        arr[i++]=n;
        getchar();
        getline(cin,ch);
        if(ar[n]==0)
        {
            ar[n]=1;
            mp[n]=ch;
        }
        else if(ar[n]==1 && mp[n]!=ch)
        {
            y=1;
        }
        if(ch=="right on")
        {
            sort(arr,arr+i);
            for(j=0;j<i;j++)
            {
                if(arr[j]==n)
                {
                    x=j;
                    break;
                }
            }
            for(j=x+1;j<i;j++)
            {
                if(mp[arr[j]]=="too low")
                {
                    y=1;
                    break;
                }
            }
            for(j=x-1;j>=0;j--)
            {
                if(mp[arr[j]]=="too high")
                {
                    y=1;
                    break;
                }
            }
            if(y==1)
            {
                printf("Stan is dishonest\n");
            }
            else if(y==0)
            {
                printf("Stan may be honest\n");
            }
            y=0;
            i=0;
            memset(ar,0,sizeof ar);
            map<int,string> mp;
        }
    }
    return 0;
}
