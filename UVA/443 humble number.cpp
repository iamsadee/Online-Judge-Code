#include<bits/stdc++.h>
using namespace std;
vector<long long int> st;
map<long long,long long> mpp;
void fun(long long n)
{
    if(n>2000000000 || mpp[n]==1 )
    {
        return;
    }
    int ar[]={2,3,5,7};
        st.push_back(n);
        mpp[n]=1;

    for(int i=0;i<=3;i++)
    {
        fun(n*ar[i]);
    }
}
int main()
{
    long long int i, x,y,a;
    fun(1);
    sort(st.begin(),st.end());
    while(scanf("%lld",&x)==1)
    {
        if(x==0)
            break;
        if(x%100>=11 && x%100<= 19)
        {
            printf("The %lldth humble number is %lld.\n",x,st[x-1]);
        }
        else if(x%10==1)
        {
            printf("The %lldst humble number is %lld.\n",x,st[x-1]);
        }
        else if(x%10==2)
        {
            printf("The %lldnd humble number is %lld.\n",x,st[x-1]);
        }
        else if(x%10==3)
        {
            printf("The %lldrd humble number is %lld.\n",x,st[x-1]);
        }
        else
        {
            printf("The %lldth humble number is %lld.\n",x,st[x-1]);
        }
    }
    return 0;
}
