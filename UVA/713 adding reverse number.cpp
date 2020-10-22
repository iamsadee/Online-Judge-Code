#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,x,y,carry,k,sum;
    string ch,ar;
    char ne[2000];
    scanf("%d",&t);
    getchar();
    for(j=1;j<=t;j++)
    {
        cin>>ch;
        cin>>ar;
        x=ch.length();
        y=ar.length();
        carry =0 ;
        k=0;
        for(i=0;i<x && i<y ;i++)
        {
            sum = (ch[i]-'0' )+ (ar[i]-'0' ) + carry ;
            carry = sum /10;
            ne[k++]=(sum %10)+'0';
        }
        if(x>y)
        {
            for(i=y;i<x;i++)
            {
                sum = (ch[i]-'0' ) + carry ;
                carry = sum /10;
                ne[k++]=sum %10+'0';
            }
        }
        else if(x<y)
        {
            for(i=x;i<y;i++)
            {
                sum = (ar[i]-'0' ) + carry ;
                carry = sum /10;
                ne[k++]=sum %10+'0';
            }
        }
        if(carry !=0)
        {
            ne[k++]=(carry)+'0';
        }
        ne[k]='\0';
        x=strlen(ne);
        y=0;
        while(ne[y++]=='0')
        {

        }
        for(i=y-1;i<x;i++)
        {
            printf("%c",ne[i]);
        }
        printf("\n");
    }
    return 0;
}
