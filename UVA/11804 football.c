#include<stdio.h>
struct player{
char name[500];
int at,def;
};

int main()

{
    struct player a[12];
    int i , j , n,k,te,tem,min,x,l,y,m ;
    char temp[500];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        min=101;
        for(j=1;j<=10;j++)
        {
            scanf("%s",a[j].name);
            scanf("%d %d",&a[j].at,&a[j].def);
        }
        for(j=1;j<=10;j++)
        {
            for(k=j+1;k<=10;k++)
            {
                if(a[j].at<=a[k].at)
                {
                    tem=a[k].at;
                    a[k].at=a[j].at;
                    a[j].at = tem;
                    strcpy(temp,a[k].name);
                    strcpy(a[k].name,a[j].name);
                    strcpy(a[j].name,temp);
                    te = a[k].def;
                    a[k].def=a[j].def;
                    a[j].def = te;
                }
            }
        }
        for(j=1;;j++)
        {
            if(min>a[j].at && j<=5)
            {
                min = a[j].at;
                x=j;
            }
            if(j>5)
            {
                if(a[j-1].at!=a[j].at)
                    break;
            }
        }
        j--;
        for(k=x;k<=j;k++)
        {
            for(l=k+1;l<=j;l++)
            {
                if(a[k].def>=a[l].def)
                {
                    tem=a[l].at;
                    a[l].at=a[k].at;
                    a[k].at = tem;
                    strcpy(temp,a[l].name);
                    strcpy(a[l].name,a[k].name);
                    strcpy(a[k].name,temp);
                    te = a[l].def;
                    a[l].def=a[k].def;
                    a[k].def = te;
                }
            }
        }
        min = 0;
        for(k=x;k<=j;k++)
        {
            if(min<a[k].def && k<=5)
            {
                min = a[k].def;
                y=k;
            }
            else if(a[k-1].def != a[k].def && k>5)
                    break;
        }
        --k;

        if(y<k)
        {
        for(l=y;l<=k;l++)
        {
            for(m=l+1;m<=k;m++)
            {
                if(strcmp(a[l].name,a[m].name)>=0){
                    strcpy(temp,a[m].name);
                    strcpy(a[m].name,a[l].name);
                    strcpy(a[l].name,temp);
                    }
            }
        }
        }
        for(l=1;l<=5;l++)
            {
                for(m=l+1;m<=5;m++)
                {
                    if(strcmp(a[l].name,a[m].name)>=0){
                    strcpy(temp,a[m].name);
                    strcpy(a[m].name,a[l].name);
                    strcpy(a[l].name,temp);
                    }
                }
            }
        for(l=6;l<=10;l++)
            {
                for(m=l+1;m<=10;m++)
                {
                    if(strcmp(a[l].name,a[m].name)>=0){
                    strcpy(temp,a[m].name);
                    strcpy(a[m].name,a[l].name);
                    strcpy(a[l].name,temp);
                    }
                }
            }
        printf("Case %d:\n",i);
        for(j=1;j<=10;j++)
        {
            if(j==1 || j==6)
                printf("(");
            printf("%s",a[j].name);
            if(j==5 || j==10)
                printf(")\n");
            else printf(", ");
        }
    }
    return 0;
}
