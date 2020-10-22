#include<stdio.h>

int main()

{
    int N , M ,i ,j, score, a , b , c , count ;

    while(scanf("%d %d",&N,&M)==2)
    {
        b=0;
        for(i=1;i<=N;i++)
        {
            c=M ;
            count = 0;
            while(c!=0)
            {
                scanf("%d",&score);
                if(score>0)
                {
                    count++ ;
                }
                c-- ;
            }
            if(count == M )
            {
                b++;
            }
        }
        printf("%d\n",b);
    }
    return 0;
}

