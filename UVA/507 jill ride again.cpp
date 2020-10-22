#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k,n,x,ans,arr[20010];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        vector<int> eta,oita;
        int sum=0,a=1,b=1,chk=0,maxsum=0;
        for(j=1;j<n;j++)
        {
            scanf("%d",&arr[j]);
            sum += arr[j];
            if(maxsum<=sum)
            {
                maxsum=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        //<<maxsum<<' '<<sum<<endl;
        sum=0;
        for(j=1;j<n;j++)
        {
            //scanf("%d",&arr[j]);
            sum += arr[j];
            //cout<<sum<<' ';
            if(maxsum==sum)
            {
                eta.push_back(b);
                oita.push_back(j+1);
                //cout<<b<<' '<<j+1<<endl;
            }
            if(sum<0)
            {
                sum=0;
                b=j+1;
            }
        }
        /*
        for(j=0;j<eta.size();j++)
        {
            printf("%d ",eta[j]);
        }
        cout<<endl;
        for(j=0;j<oita.size();j++)
        {
            printf("%d ",oita[j]);
        }
        cout<<endl;*/

        int mx=0;
        for(j=0;j<eta.size();j++)
        {
            mx=max(abs(oita[j]-eta[j]),mx);
        }
        for(j=0;j<eta.size();j++)
        {
            if(mx==(abs(eta[j]-oita[j])))
            {
                a=eta[j];
                b=oita[j];
                break;
            }
        }
        if(mx==0)
        {
            printf("Route %d has no nice parts\n",i);
        }
        else printf("The nicest part of route %d is between stops %d and %d\n",i,a,b);
    }
    return 0;
}
