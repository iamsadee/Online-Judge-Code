#include<stdio.h>
int main()

{
    int T, N , i ,j,a,b,c,d,e,f,g,h ,x, y,A,B,rem;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        a = 0 , b= 0 , c= 0 , d = 0 ;
        e = 0 , f = 0 , g = 0 , h = 0 , x= 0 ;
        y = 0;
        for(j=0;j<=N;j++)
        {
            A = j ;
            if(N==0)
            {
                a++;
            }
            while(A!=0)
            {
                rem = A%10 ;
                if(rem==0)
                {
                    a++;
                }
                else if(rem ==1)
                {
                    b++;
                }
                else if(rem ==2)
                {
                    c++;
                }
                else if(rem ==3)
                {
                    d++;
                }
                else if(rem ==4)
                {
                    e++;
                }
                else if(rem ==5)
                {
                    f++;
                }
                else if(rem ==6)
                {
                    g++;
                }
                else if(rem ==7)
                {
                    h++;
                }
                else if(rem ==8)
                {
                    x++;
                }
                else if(rem ==9)
                {
                    y++;
                }
                A = A/10 ;
            }
        }

        printf("%d %d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,x,y);
    }
    return 0;
}
