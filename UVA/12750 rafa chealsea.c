#include<stdio.h>
int main()
{
    int T , i , j , k,n;
    char ch[501];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        getchar();
        for(j=0;j<n;j++)
        {
            scanf("%c",&ch[j]);
            getchar();
        }
        k=0;
        for(j=0;j<n;j++)
        {
            if(ch[j]=='W')
            {
                k=0;
            }
            else k++;
            if(k>2)
                break;
        }
        if(k>2)
            printf("Case %d: %d\n",i,j+1);
        else printf("Case %d: Yay! Mighty Rafa persists!\n",i);
    }
    return 0;
}
