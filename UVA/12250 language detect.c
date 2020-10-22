#include<stdio.h>
#include<string.h>
int main()

{
    int i=1 ;
    char S[14] ;
    for(;S!='#';)
    {
        scanf("%s",S);

        if(strcmp(S,"#")==0)
            break;
        else if(strcmp(S,"HELLO")==0)
            printf("Case %d: ENGLISH\n",i);
        else if(strcmp(S,"HALLO")==0)
            printf("Case %d: GERMAN\n",i);
        else if(strcmp(S,"HOLA")==0)
            printf("Case %d: SPANISH\n",i);
        else if(strcmp(S,"BONJOUR")==0)
            printf("Case %d: FRENCH\n",i);
        else if(strcmp(S,"CIAO")==0)
            printf("Case %d: ITALIAN\n",i);
        else if(strcmp(S,"ZDRAVSTVUJTE")==0)
            printf("Case %d: RUSSIAN\n",i);
        else printf("Case %d: UNKNOWN\n",i);
        i++ ;
    }
    return 0;
}
