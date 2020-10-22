#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1000];
    int i,j,k,l,x,y,z,count,a;
    while(gets(ch))
    {
        x=strlen(ch);
        j=x-1;
        count=0;
        a=0;
        k=0;
        for(i=0;i<x;i++)
        {
            if(ch[i]==ch[j])
                count++;
            else break;
            j--;
        }
        if(count==x)
        {
            a=1;
        }
        count=0;
        j=x-1;
        for(i=0;i<x;i++)
        {
            if(ch[i]=='A' && ch[j]=='A')
                count++;
            else if((ch[i]=='E' && ch[j]=='3' ) || (ch[j]=='E' && ch[i]=='3'))
                count++;
            else if(ch[i]=='H' && ch[j]=='H')
                count++;
            else if(ch[i]=='I' && ch[j]=='I')
                count++;
            else if((ch[i]=='J' && ch[j]=='L' ) || (ch[j]=='J' && ch[i]=='L'))
                count++;
            else if(ch[i]=='M' && ch[j]=='M')
                count++;
            else if(ch[i]=='O' && ch[j]=='O')
                count++;
            else if((ch[i]=='S' && ch[j]=='2' ) || (ch[j]=='S' && ch[i]=='2'))
                count++;
            else if(ch[i]=='T' && ch[j]=='T')
                count++;
            else if(ch[i]=='U' && ch[j]=='U')
                count++;
            else if(ch[i]=='V' && ch[j]=='V')
                count++;
            else if(ch[i]=='X' && ch[j]=='X')
                count++;
            else if(ch[i]=='Y' && ch[j]=='Y')
                count++;
            else if((ch[i]=='Z' && ch[j]=='5' ) || (ch[j]=='Z' && ch[i]=='5'))
                count++;
            else if(ch[i]=='1' && ch[j]=='1')
                count++;
            else if(ch[i]=='8' && ch[j]=='8')
                count++;
            else break;

            j--;
        }
        if(count==x)
        {
            k=1;
        }
        if(a==1 && k==1)
        {
            printf("%s -- is a mirrored palindrome.\n",ch);
        }
        else if(a==1 && k==0)
        {
            printf("%s -- is a regular palindrome.\n",ch);
        }
        else if(a==0 && k==1)
        {
            printf("%s -- is a mirrored string.\n",ch);
        }
        else if(a==0 && k==0)
        {
            printf("%s -- is not a palindrome.\n",ch);
        }
        printf("\n");
    }
    return 0;
}
