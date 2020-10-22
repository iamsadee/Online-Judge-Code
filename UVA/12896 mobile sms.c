#include<stdio.h>
int main()
{
    long long int arr[101],n,ar[101],i,j,T;
    char str[101];
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        for(j=0;j<n;j++)
        {
            scanf("%lld",&ar[j]);
        }
        for(j=0;j<n;j++)
        {
            if(arr[j]==1 && ar[j]==1)
            {
                str[j]='.';
            }
            else if(arr[j]==1 && ar[j]==2)
            {
                str[j]=',';
            }
            else if(arr[j]==1 && ar[j]==3)
            {
                str[j]='?';
            }
            else if(arr[j]==1 && ar[j]==4)
            {
                str[j]='"';
            }
            else if(arr[j]==2 && ar[j]==1)
            {
                str[j]='a';
            }
            else if(arr[j]==2 && ar[j]==2)
            {
                str[j]='b';
            }
            else if(arr[j]==2 && ar[j]==3)
            {
                str[j]='c';
            }
            else if(arr[j]==3 && ar[j]==1)
            {
                str[j]='d';
            }
            else if(arr[j]==3 && ar[j]==2)
            {
                str[j]='e';
            }
            else if(arr[j]==3 && ar[j]==3)
            {
                str[j]='f';
            }
            else if(arr[j]==4 && ar[j]==1)
            {
                str[j]='g';
            }
            else if(arr[j]==4 && ar[j]==2)
            {
                str[j]='h';
            }
            else if(arr[j]==4 && ar[j]==3)
            {
                str[j]='i';
            }
            else if(arr[j]==5 && ar[j]==1)
            {
                str[j]='j';
            }
            else if(arr[j]==5 && ar[j]==2)
            {
                str[j]='k';
            }
            else if(arr[j]==5 && ar[j]==3)
            {
                str[j]='l';
            }
            else if(arr[j]==6 && ar[j]==1)
            {
                str[j]='m';
            }
            else if(arr[j]==6 && ar[j]==2)
            {
                str[j]='n';
            }
            else if(arr[j]==6 && ar[j]==3)
            {
                str[j]='o';
            }
            else if(arr[j]==7 && ar[j]==1)
            {
                str[j]='p';
            }
            else if(arr[j]==7 && ar[j]==2)
            {
                str[j]='q';
            }
            else if(arr[j]==7 && ar[j]==3)
            {
                str[j]='r';
            }
            else if(arr[j]==7 && ar[j]==4)
            {
                str[j]='s';
            }
            else if(arr[j]==8 && ar[j]==1)
            {
                str[j]='t';
            }
            else if(arr[j]==8 && ar[j]==2)
            {
                str[j]='u';
            }
            else if(arr[j]==8 && ar[j]==3)
            {
                str[j]='v';
            }
            else if(arr[j]==9 && ar[j]==1)
            {
                str[j]='w';
            }
            else if(arr[j]==9 && ar[j]==2)
            {
                str[j]='x';
            }
            else if(arr[j]==9 && ar[j]==3)
            {
                str[j]='y';
            }
            else if(arr[j]==9 && ar[j]==4)
            {
                str[j]='z';
            }
            else if(arr[j]==0 && ar[j]==1)
            {
                str[j]=' ';
            }
        }
        str[j]='\0';
        printf("%s\n",str);
    }
    return 0;
}
