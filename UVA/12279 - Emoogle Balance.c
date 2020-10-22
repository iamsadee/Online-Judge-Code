#include<stdio.h>

int main()

{
    int N , i , j=1 , k ,l, arr[1000];
    while(scanf("%d",&N)==1)
    {
        l=0 ;
        k=0 ;
        if(N==0)
            break;
        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]==0)
            {
                l++;
            }
            else if(arr[i] !=0)
            {
                k++;
            }
        }
        printf("Case %d: %d\n",j,k-l);
        j++;


    }
    return 0;
}
