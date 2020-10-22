#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Z,I,M,L;
    int i=1;
    while(scanf("%d %d %d %d",&Z,&I,&M,&L)==4)
    {
        if(Z==0 && I==0 && M==0 && L==0)
            break;
        bool arr[10000];
        memset(arr,0,sizeof arr);
        long long cnt=0;
        int ans=0;
        while(1)
        {
            ans = ((Z*L)+I)%M;
            if(arr[ans]==1)
                break;
            else{
            cnt++;
            arr[ans]=1;
            L=ans;
            }
        }
        //cnt++;
        printf("Case %d: %lld\n",i++,cnt);
    }
    return 0;
}
