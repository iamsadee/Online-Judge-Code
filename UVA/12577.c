#include<stdio.h>
#include<string.h>

int main()

{
    long long int i ;
    char ch[10] ;
    i=1;
    for(;ch != '*';)
    {
        scanf("%s",ch);
        if(strcmp(ch , "Hajj")==0)
            printf("Case %lld: Hajj-e-Akbar\n",i);
        else if(strcmp(ch,"Umrah")==0)
            printf("Case %lld: Hajj-e-Asghar\n",i);
        else if(strcmp(ch,"*")==0)
            break;
            i++;
    }
    return 0;
}
