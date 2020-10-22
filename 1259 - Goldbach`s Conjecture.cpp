#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static bool arr[10000000];
vector<int> prime;
void seive()
{
    int n=10000000;
    int x=sqrt(n);
    int i,j;
    arr[0]=1;
    arr[1]=1;
    for(i=4; i<=n; i+=2)
    {
        arr[i]=1;
    }
    for(i=3; i<=x; i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i; j<=n; j+= 2*i)
            {
                arr[j]=1;
            }
        }
    }
    for(i=2; i<=n; i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}
int main()
{
    int t,k;
    seive();
    //cout<<prime.size()<<endl;
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        int n;
        scanf("%d",&n);
        int cnt=0;
    //cout<<prime[prime.size()-1]<<endl;
        for(int i=0;i<prime.size();i++)
        {
            //cout<<i<<endl;
            if(prime[i]>n)
                break;
                //cout<<n-prime[i]<<endl;
            if( ((n-prime[i])>=prime[i]) && arr[n-prime[i]]==false ) cnt++;
        }
        printf("Case %d: %d\n",k,cnt);

        //printf("Case %d: %lld\n",k,res);
    }
    return 0;
}
