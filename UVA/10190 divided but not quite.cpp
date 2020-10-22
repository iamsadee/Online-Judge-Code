#include<bits/stdc++.h>
using namespace std;
vector<long long int> arr;
int main()
{
    long long i,j,k,x,y,a;
    vector<int> arr;
    while(scanf("%lld %lld",&x,&y)==2)
    {
        a=x;
        arr.push_back(x);
        j=1;
        k=0;
        if(y==0 || y==1 || x==0)
        {
            printf("Boring!\n");
            arr.clear();
        }
        else{
        while(1)
        {
            if(x%y!=0)
                {
                    k=1;
                    break;
                }
            x=x/y;
            arr.push_back(x);
            if(x==1 )
                break;
        }
        }
        if(k==1)
            printf("Boring!\n");
        else
        {
            j=arr.size();
            for(i=0;i<j;i++)
            {
                printf("%d",arr[i]);
                if(i<j-1)
                    printf(" ");
                else printf("\n");
            }
        }
        arr.clear();
    }
    return 0;
}

