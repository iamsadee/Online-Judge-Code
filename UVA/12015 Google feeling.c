#include<stdio.h>
#include<string.h>
int main()
{
    char ch[11][100];
    int i , j , T , arr[11] ,mx;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        mx =0;
        for(j=0;j<10;j++)
        {
            scanf("%s%d",ch[j],&arr[j]);
            if(mx<=arr[j])
            {
                mx = arr[j];
            }
        }
        printf("Case #%d:\n",i);
        for(j=0;j<10;j++)
        {
            if(arr[j]==mx)
            {
                printf("%s\n",ch[j]);
            }
        }
    }
    return 0;
}
