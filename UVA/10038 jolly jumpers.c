#include<stdio.h>
int main()
{
    int n , i ,j ,k,m, num[3000] , x[3000] ,temp;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        j = n-1;
        m=1;
        if(n>1)
        {
            for(i=0;i<j;i++)
            {
                x[i] = abs(num[i] - num[i+1]) ;
                if(x[i]>=n)
                {
                    m=0;
                    break;
                }
            }
            if(m!=0){
            for(i=0;i<j;i++)
            {
                k=i ;
                while(k>=1 && x[k]<=x[k-1])
                {
                    temp = x[k-1] ;
                    x[k-1] = x[k] ;
                    x[k] = temp ;
                    k--;
                }
            }
            for(i=0;i<j-1;i++)
            {
                if(x[i]==x[i+1])
                {
                    m=0 ;
                    break;
                }
            }
          }
        }
        if(m==0)
          {
              printf("Not jolly\n");
          }
        else printf("Jolly\n");
    }
    return 0;
}
