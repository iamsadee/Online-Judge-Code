#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,arr[20005],ar[20005];
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0 && m==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&ar[i]);
        }
        sort(arr,arr+n);
        sort(ar,ar+m);
        int chk=0,sum=0;
        i=0;
        for(j=0;j<m;j++)
        {
            if(i==n)
                break;
            if(arr[i]<=ar[j])
            {
                i++;
                sum += ar[j];
                chk++;
            }
        }
        if(chk==n)
            printf("%d\n",sum);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
