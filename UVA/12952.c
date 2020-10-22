#include<stdio.h>
int main()

{
    int A , B ;
    while(scanf("%d %d",&A,&B)==2)
    {
        if(A>=B)
            printf("%d\n",A);
        else if(B>=A)
            printf("%d\n",B);
    }
    return 0;
}
