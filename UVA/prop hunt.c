#include<stdio.h>
int main()

{
    int p , h , o , x ;

    while(scanf("%d %d %d",&p,&h,&o)==3)
    {
        x = o - p ;

        if(h<=x)
        {
            printf("Props win!\n");
        }
        else if(h>x && h!=x)
        {
            printf("Hunters win!\n");
        }
    }
    return 0;
}
