#include<stdio.h>
#include<math.h>
int main()
{
    int l,i,j,k,mx,count,x,y,a,b,z,zx;
    char ch[2000001];
    while(scanf("%lld",&l)==1)
    {
        a=0;
        b=0;
        zx=0;
        if(l==0)
            break;
        mx=2000002;
        getchar();
        scanf("%s",ch);
        for(i=0;i<l;i++)
        {
            if(ch[i]=='Z')
            {
                mx=0;
                zx=1;
                break;
            }
            if(ch[i]=='D')
            {
                x=i;
                a=1;
            }
            if(ch[i]=='R')
            {
                y=i;
                b=1;
            }
            if(a==1 && b==1)
            {
                z=abs(x-y);
                if(mx>z)
                {
                    mx=z;
                }
                if(x>y)
                {
                    b=0;
                }

                else a=0;
            }
        }
        if(zx==1)
            printf("0\n");
        else printf("%d\n",mx);

    }
    return 0;
}
