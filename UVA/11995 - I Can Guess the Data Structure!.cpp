#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i,j;
        ll x;
        stack<ll> st;
        queue<ll> q;
        priority_queue<ll> pq;
        int a=0,b=0,c=0,d=0,e=0;
        int chk1=0,chk2=0,chk3=0,y=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&j);
            if(j==1)
            {
                scanf("%lld",&x);
                pq.push(x);
                st.push(x);
                q.push(x);
            }
            else if(j==2)
            {
                y++;
                scanf("%lld",&x);
                if(pq.size()==0 && st.size()==0 && q.size()==0)
                {
                    d=1;
                }
                if(pq.size()>0)
                {
                    if(pq.top()==x )
                    {
                        a=1;
                        chk1++;
                        pq.pop();
                    }
                    else if(pq.top()!=x )
                    {
                        a=0;
                    }
                }
                if(q.size()>0)
                {
                    if(q.front()==x )
                    {
                        b=1;
                        chk2++;
                        q.pop();
                    }
                    else if(q.front()!=x )
                    {
                        b=0;
                    }
                }
                if(st.size()>0)
                {
                    if(st.top()==x )
                    {
                        c=1;
                        chk3++;
                        st.pop();
                    }
                    else if(st.top()!=x )
                    {
                        c=0;
                    }
                }

            }
        }

        if(chk1!=y && chk2!=y && chk3!=y)
        {
            printf("impossible\n");
        }
        else if(chk1==y && chk2==y )
        {
            printf("not sure\n");
        }
        else if(chk1==y && chk3==y)
        {
            printf("not sure\n");
        }
        else if(chk2==y && chk3==y)
        {
            printf("not sure\n");
        }
        else if(chk1==y)
        {
            printf("priority queue\n");
        }
        else if(chk2==y)
        {
            printf("queue\n");
        }
        else if(chk3==y)
        {
            printf("stack\n");
        }
    }
    return 0;
}
