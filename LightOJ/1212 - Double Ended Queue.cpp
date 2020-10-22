#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",i);
        deque<int> dq;
        for(int j=1;j<=m;j++)
        {
            string ch;
            cin>>ch;
            if(ch=="pushLeft")
            {
                int x;
                cin>>x;
                if(dq.size()<n)
                {
                    dq.push_front(x);
                    printf("Pushed in left: %d\n",x);
                }
                else
                {
                    cout<<"The queue is full"<<'\n';
                }
            }
            else if(ch=="pushRight")
            {
                int x;
                cin>>x;
                if(dq.size()<n)
                {
                    dq.push_back(x);
                    printf("Pushed in right: %d\n",x);
                }
                else
                {
                    cout<<"The queue is full"<<'\n';
                }
            }
            else if(ch=="popLeft")
            {
                if(dq.size()>0)
                {
                    int x=dq.front();
                    printf("Popped from left: %d\n",x);
                    dq.pop_front();
                }
                else
                {
                    cout<<"The queue is empty"<<'\n';
                }
            }
            else if(ch=="popRight")
            {
                if(dq.size()>0)
                {
                    int x=dq.back();
                    printf("Popped from right: %d\n",x);
                    dq.pop_back();
                }
                else
                {
                    cout<<"The queue is empty"<<'\n';
                }
            }
        }
    }
    return 0;
}
