#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k=1;;
    int arr[]= {10000000,100000,1000,100};
    while(scanf("%lld",&n)==1)
    {
        int a=k,o=0;
        while(a!=0)
        {
            a=a/10;
            o++;
        }
        for(int l=o;l<4;l++)
        {
            printf(" ");
        }
        printf("%d. ",k++);
        int i=0,j;
        ll p=n;
        for(i=0; i<4; i++)
        {
            int x=n/arr[i];
            n=n%arr[i];
            if(i==0 && x>0)
            {
                for(j=0; j<4; j++)
                {
                    int y=x/arr[j];
                    x=x%arr[j];
                    if(j==0 && y>0)
                    {
                        printf("%d kuti ",y);
                    }
                    else if(j==1 && y>0)
                    {
                        printf("%d lakh ",y);
                    }
                    else if(j==2 && y>0 )
                    {
                        printf("%d hajar ",y);
                    }
                    else if(j==3 && y>0)
                    {
                        printf("%d shata ",y);
                    }
                }
                if(x>0)
                {
                    printf("%d ",x);
                }
                printf("kuti");
                if(n>0)
                {
                    printf(" ");
                }
            }
            else if(i==1 && x>0)
            {
                printf("%d lakh",x);
                if(n>0)
                {
                    printf(" ");
                }
            }
            else if(i==2 && x>0)
            {
                printf("%d hajar",x);
                if(n>0)
                {
                    printf(" ");
                }
            }
            else if(i==3 && x>0)
            {
                printf("%d shata",x);
                if(n>0)
                {
                    printf(" ");
                }
            }
            if(n>0 && i==3)
            {
                printf("%d",n);
            }
            if(i==3 && p==0)
            {
                printf("0");
            }
            if(i==3)
                printf("\n");
        }
    }
    return 0;
}
