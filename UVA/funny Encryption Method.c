#include<stdio.h>
int main()
{
    int t,n,i,j,k,x,y,count;
    char ch[10];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        x=n;
        count=0;
        while(n!=0)
        {
            y=n%2;
            if(y==1)
                count++;
            n=n/2;
        }
        n=x;
        j=0;
        while(n!=0)
        {
            ch[j]=(n%10)+'0';
            n=n/10;
            j++;
        }
        ch[j]='\0';
        printf("%d ",count);
        count=0;
        for(k=j-1;k>=0;k--)
        {
            if(ch[k]=='1')
                count+=1;
            else if(ch[k]=='2')
                count+=1;
            else if(ch[k]=='3')
                count+=2;
            else if(ch[k]=='4')
                count+=1;
            else if(ch[k]=='5')
                count+=2;
            else if(ch[k]=='0')
                count+=0;
            else if(ch[k]=='6')
                count+=2;
            else if(ch[k]=='7')
                count+=3;
            else if(ch[k]=='8')
                count+=1;
            else if(ch[k]=='9')
                count+=2;
            else if(ch[k]=='10')
                count+=2;
            else if(ch[k]=='11')
                count+=3;
            else if(ch[k]=='12')
                count+=2;
            else if(ch[k]=='13')
                count+=3;
            else if(ch[k]=='14')
                count+=3;
            else if(ch[k]=='15')
                count+=4;
        }
        printf("%d\n",count);
    }
    return 0;
}
