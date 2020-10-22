#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,arr[10000],ar[10000],n,m,x,y;
    double sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        j=0;
        while(scanf("%d",&x)==1)
        {
            if(x==0)
               break;
            arr[j++]=x;
        }
        sort(arr,arr+j,greater<int>());
        sum =0;
        for(int k=0;k<j;k++)
        {
            sum += (2*pow(arr[k]*1.0,(k+1)*1.0));
            if(sum>5000000)
            {
                sum =-1;
                break;
            }
        }
        if(sum == -1)
        {
            printf("Too expensive\n");
        }
        else printf("%0.0lf\n",sum);
    }
    return 0;
}
