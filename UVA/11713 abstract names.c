#include<stdio.h>
#include<string.h>
int main()
{
    int n ,i,j , a , b , k,m,x;
    char str[2][20] , ch[20] , st[20];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        x = 1 ;
        k=1;
        m=0 ;
        for(j=0;j<2;j++)
        {
            scanf("%s",str[j]);
        }
        a = strlen(str[0]) ;
        b = strlen(str[1]) ;
        if(a==b)
        {
            for(j=0;str[1][j]!='\0';j++)
            {
               if(str[0][j] != 'e' && str[0][j]!='o' && str[0][j] != 'a' && str[0][j]!='i' && str[0][j] != 'u' )
               {
                   st[m] = str[1][j];
                   ch[m] = str[0][j] ;
                   m++;
               }
               else
               {
                  if(str[1][j] == 'a' || str[1][j]=='e' || str[1][j] == 'i' || str[1][j]=='o' || str[1][j] == 'u' )
                  {
                      x=x ;
                  }
                  else
                  {
                      x = 0 ;
                  }
               }
            }
            st[m] = '\0' , ch[m]= '\0' ;
            if(!strcmp(st,ch) && x==1)
            {
                printf("Yes\n");
            }
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}
