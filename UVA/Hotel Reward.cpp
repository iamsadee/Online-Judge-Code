#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[1005];
    int n,k;
    while(cin>>n)
    {
        cin>>k;
        //hotel arr[100005];
        ll x;
        ll sum=0;
        ll nilam=0;
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<n;i++,nilam++)
        {
            ll val;
            cin>>val;
            sum += val;
            if(nilam==k)
            {
                nilam=-1;
                pq.push(val);
            }
            else if(pq.size()>0)
            {
                int tp=pq.top();
                if(tp<val)
                {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
        while(!(pq.empty()))
        {
            sum -= pq.top();
            pq.pop();
        }
        cout<<sum<<endl;

    }
    return 0;
}
