#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100000],str[100000] ;
    int i ;
    while(gets(ch))
    {
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]=='1')
                str[i]='`';
            else if(ch[i]=='2')
                str[i]='1';
            else if(ch[i]=='3')
                str[i]='2';
            else if(ch[i]=='4')
                str[i]='3';
            else if(ch[i]=='5')
                str[i]='4';
            else if(ch[i]=='6')
                str[i]='5';
            else if(ch[i]=='7')
                str[i]='6';
            else if(ch[i]=='8')
                str[i]='7';
            else if(ch[i]=='9')
                str[i]='8';
            else if(ch[i]=='0')
                str[i]='9';
            else if(ch[i]=='-')
                str[i]='0';
            else if(ch[i]=='=')
                str[i]='-';
            else if(ch[i]=='W')
                str[i]='Q';
            else if(ch[i]=='E')
                str[i]='W';
            else if(ch[i]=='R')
                str[i]='E';
            else if(ch[i]=='T')
                str[i]='R';
            else if(ch[i]=='Y')
                str[i]='T';
            else if(ch[i]=='U')
                str[i]='Y';
            else if(ch[i]=='I')
                str[i]='U';
            else if(ch[i]=='O')
                str[i]='I';
            else if(ch[i]=='P')
                str[i]='O';
            else if(ch[i]=='[')
                str[i]='P';
            else if(ch[i]==']')
                str[i]='[';
            else if(ch[i]=='S')
                str[i]='A';
            else if(ch[i]=='D')
                str[i]='S';
            else if(ch[i]=='F')
                str[i]='D';
            else if(ch[i]=='G')
                str[i]='F';
            else if(ch[i]=='H')
                str[i]='G';
            else if(ch[i]=='J')
                str[i]='H';
            else if(ch[i]=='K')
                str[i]='J';
            else if(ch[i]=='L')
                str[i]='K';
            else if(ch[i]==';')
                str[i]='L';
            else if(ch[i]=='X')
                str[i]='Z';
            else if(ch[i]=='C')
                str[i]='X';
            else if(ch[i]=='V')
                str[i]='C';
            else if(ch[i]=='B')
                str[i]='V';
            else if(ch[i]=='N')
                str[i]='B';
            else if(ch[i]=='M')
                str[i]='N';
            else if(ch[i]==',')
                str[i]='M';
            else if(ch[i]=='.')
                str[i]=',';
            else if(ch[i]=='/')
                str[i]='.';
            else if(ch[i]==' ')
                str[i]=' ';
            else if(ch[i]=='\\')
                str[i]=']';
            else if(ch[i]=='\'')
                str[i]=';';

        }
        str[i]='\0';
        printf("%s\n",str);
    }
    return 0;
}
