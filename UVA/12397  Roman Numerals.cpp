#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,x,y,count;
    while(scanf("%d",&y)==1)
    {
        count =0;
        x=y;
        i=0;
        while(x!=0)
        {
            j=x%10;
            x=x/10;
            if(i==0)
            {
                if(j==1)
                {
                    count+=1;
                }
                else if(j==2)
                {
                    count+=2;
                }
                else if(j==3)
                {
                    count+=3;
                }
                else if(j==4)
                {
                    count+=3;
                }
                else if(j==5)
                {
                    count+=2;
                }
                else if(j==6)
                {
                    count+=3;
                }
                else if(j==7)
                {
                    count+=4;
                }
                else if(j==8)
                {
                    count+=5;
                }
                else if(j==9)
                {
                    count+=3;
                }
            }
            else if(i==1)
            {
                if(j==1)
                {
                    count+=2;
                }
                else if(j==2)
                {
                    count+=4;
                }
                else if(j==3)
                {
                    count+=6;
                }
                else if(j==4)
                {
                    count+=4;
                }
                else if(j==5)
                {
                    count+=2;
                }
                else if(j==6)
                {
                    count+=4;
                }
                else if(j==7)
                {
                    count+=6;
                }
                else if(j==8)
                {
                    count+=8;
                }
                else if(j==9)
                {
                    count+=4;
                }
            }
            else if(i==2)
            {
                if(j==1)
                {
                    count+=2;
                }
                else if(j==2)
                {
                    count+=4;
                }
                else if(j==3)
                {
                    count+=6;
                }
                else if(j==4)
                {
                    count+=5;
                }
                else if(j==5)
                {
                    count+=3;
                }
                else if(j==6)
                {
                    count+=5;
                }
                else if(j==7)
                {
                    count+=7;
                }
                else if(j==8)
                {
                    count+=9;
                }
                else if(j==9)
                {
                    count+=6;
                }
            }
            else if(i==3)
            {
                if(j==1)
                {
                    count+=4;
                }
                else if(j==2)
                {
                    count+=8;
                }
                else if(j==3)
                {
                    count+=12;
                }
            }
            i++;
        }
        printf("%d\n",count);
    }
    return 0;
}
