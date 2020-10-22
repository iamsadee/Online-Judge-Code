#include<stdio.h>
int main()
{
    int A , B , C , D , E , N , i ;
    while(scanf("%d",&N)==1)
    {
        if(N==0)
            break;
        for(i=1;i<=N;i++)
        {
            scanf("%d %d %d %d %d",&A,&B,&C,&D,&E);
            if(A<128 && B>127 && C>127 && D>127 && E>127)
                printf("A\n");
            else if(B<128 && A>127 && C>127 && D>127 && E>127)
                printf("B\n");

            else if(C<128 && A>127 && B>127 && D>127 && E>127)
                printf("C\n");
            else if(D<128 && A>127 && C>127 && B>127 && E>127)
                printf("D\n");
            else if(E<128 && A>127 && C>127 && D>127 && B>127)
                printf("E\n");
            else printf("*\n");

        }

    }
    return 0;

}
