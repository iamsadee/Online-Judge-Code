#include<bits/stdc++.h>
using namespace std;
int arr[100005],dp[100005],dir[100005];
int j=0;
int fun(int x)
{
    int y;
    if(dp[x]!=-1)
        return dp[x];
    int mx=0;
    for(y=x+1;y<j;y++)
    {
        if(arr[y]>arr[x])
        {
            if(fun(y)>mx)
            {
                mx=fun(y);
                dir[x]=y;
            }
        }
    }
    return dp[x]=1+mx;
}
//int start;
void solution(int start)
{
	while(dir[start]!=-1)
	{
		printf("%d\n",arr[start]);
		start=dir[start];
		//cout<<start<<endl;
	}
	cout<<dir[4]<<endl;
}
int main()
{
    j=0;
    while(scanf("%d",&arr[j])==1)
    {
        j++;
    }
    memset(dp,-1,sizeof dp);
    memset(dir,-1,sizeof dir);
    int mx=0,start;
    for(int i=0;i<j;i++)
    {
        if(mx<=fun(i))
        {
            start=i;
            mx=fun(i);
        }
    }
    cout<<mx<<endl;
    cout<<"-"<<endl;
    solution(start);
    return 0;
}
