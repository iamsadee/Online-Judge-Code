#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        int arr[105];
        int i,j,m;
        int flag=0;
        for(i=1; i<=4*n; i++)
        {
            if(flag==1)
                break;
            m=i;
            queue<int> q;
            for(j=2; j<=n; j++)
            {
                q.push(j);
            }
            //memset(arr,0,sizeof arr);
            int chk=1;
            int cnt=0;
            while(!(q.empty()))
            {
                int y=q.front();
                cnt++;
                if(cnt==m && y==2 && (chk+1)==n)
                {
                    flag=1;
                    cnt=0;
                    break;
                }
                if(cnt==m)
                {
                    chk++;
                    //cout<<y<<endl;
                    cnt=0;
                    q.pop();
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        cout<<m<<'\n';
    }
    return 0;
}
