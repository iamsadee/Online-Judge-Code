#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[51],n,i,j,k,mx,x,y,count,l=1;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        mx=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            mx += arr[i];
        }
        x=mx/n;
        count=0;
        y=0;
        sort(arr,arr+n);
        j=0;
        for(k=n-1;k>=0;k--)
        {
            if(arr[k]>x)
            {
                while(arr[k]>x)
                {
                    y++;
                    arr[k]-=1;
                    count++;
                }
            }
            if(arr[j]<x)
            {
                while(arr[j]<x && y>0)
                {
                    arr[j]+=1;
                    y--;
                }
            }
            j++;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",l,count);
        l++;
    }
    return 0;
}
