#include<stdio.h>
int main()

{
    int C , N , i , j ,k=1 , mark[1000]     ;
    float avg, per    ;
    scanf("%d",&C);
    for(i=1;i<=C;i++)
    {

        scanf("%d",&N);
        int sum = 0;
        for(j=1;j<=N;j++)
        {
            scanf("%d",&mark[j]);
            sum += mark[j];
        }

        avg = (sum*1.000)/N ;
        int count = 0 ;
        for(k=1;k<=N;k++)
        {
            if( mark[k] >avg)
            count++;
        }
        per = count*(100.000/N) ;
        printf("%0.3f%%\n",per);


    }

}
