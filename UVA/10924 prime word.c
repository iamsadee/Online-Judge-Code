#include<stdio.h>
int prime(int n)
{
    int i , x ,count=1;
    x = sqrt(n);
    for(i=2;i<=x;i++)
    {
        if(n%i==0)
        {
            count = 0;
        }
    }
    return count;
}
int main()
{
    char ch[31];
    int sum ,i , k;
    while(gets(ch))
    {
        sum =0 ;
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]=='a')
            {
                sum += 1 ;
            }
            else if(ch[i]=='b')
            {
                sum += 2 ;
            }
            else if(ch[i]=='c')
            {
                sum += 3 ;
            }
            else if(ch[i]=='d')
            {
                sum += 4 ;
            }
            else if(ch[i]=='e')
            {
                sum += 5 ;
            }
            else if(ch[i]=='f')
            {
                sum += 6 ;
            }
            else if(ch[i]=='g')
            {
                sum += 7 ;
            }
            if(ch[i]=='h')
            {
                sum += 8 ;
            }
            else if(ch[i]=='i')
            {
                sum += 9 ;
            }
            else if(ch[i]=='j')
            {
                sum += 10 ;
            }
            else if(ch[i]=='k')
            {
                sum += 11 ;
            }
            else if(ch[i]=='l')
            {
                sum += 12 ;
            }
            else if(ch[i]=='m')
            {
                sum += 13 ;
            }
            if(ch[i]=='n')
            {
                sum += 14 ;
            }
            else if(ch[i]=='o')
            {
                sum += 15 ;
            }
            else if(ch[i]=='p')
            {
                sum += 16 ;
            }
            else if(ch[i]=='q')
            {
                sum += 17 ;
            }
            else if(ch[i]=='r')
            {
                sum += 18 ;
            }
            else if(ch[i]=='s')
            {
                sum += 19 ;
            }
            else if(ch[i]=='t')
            {
                sum += 20 ;
            }
            else if(ch[i]=='u')
            {
                sum += 21 ;
            }
            else if(ch[i]=='v')
            {
                sum += 22 ;
            }
            else if(ch[i]=='w')
            {
                sum += 23 ;
            }
            else if(ch[i]=='x')
            {
                sum += 24 ;
            }
            else if(ch[i]=='y')
            {
                sum += 25 ;
            }
            else if(ch[i]=='z')
            {
                sum += 26 ;
            }
            else if(ch[i]=='A')
            {
                sum += 27 ;
            }
            else if(ch[i]=='B')
            {
                sum += 28 ;
            }
            else if(ch[i]=='C')
            {
                sum += 29 ;
            }
            else if(ch[i]=='D')
            {
                sum += 30 ;
            }
            else if(ch[i]=='E')
            {
                sum += 31 ;
            }
            else if(ch[i]=='F')
            {
                sum += 32 ;
            }
            else if(ch[i]=='G')
            {
                sum += 33 ;
            }
            if(ch[i]=='H')
            {
                sum += 34 ;
            }
            else if(ch[i]=='I')
            {
                sum += 35 ;
            }
            else if(ch[i]=='J')
            {
                sum += 36 ;
            }
            else if(ch[i]=='K')
            {
                sum += 37 ;
            }
            else if(ch[i]=='L')
            {
                sum += 38 ;
            }
            else if(ch[i]=='M')
            {
                sum += 39 ;
            }
            if(ch[i]=='N')
            {
                sum += 40 ;
            }
            else if(ch[i]=='O')
            {
                sum += 41 ;
            }
            else if(ch[i]=='P')
            {
                sum += 42 ;
            }
            else if(ch[i]=='Q')
            {
                sum += 43 ;
            }
            else if(ch[i]=='R')
            {
                sum += 44 ;
            }
            else if(ch[i]=='S')
            {
                sum += 45 ;
            }
            else if(ch[i]=='T')
            {
                sum += 46 ;
            }
            else if(ch[i]=='U')
            {
                sum += 47 ;
            }
            else if(ch[i]=='V')
            {
                sum += 48 ;
            }
            else if(ch[i]=='W')
            {
                sum += 49 ;
            }
            else if(ch[i]=='X')
            {
                sum += 50 ;
            }
            else if(ch[i]=='Y')
            {
                sum += 51 ;
            }
            else if(ch[i]=='Z')
            {
                sum += 52 ;
            }
        }
        k = prime(sum);
        if(k==1)
        {
            printf("It is a prime word.\n");
        }
        else printf("It is not a prime word.\n");
    }
    return 0;
}
