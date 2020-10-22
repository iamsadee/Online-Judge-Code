#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool
vector<int> arr;
bool chk;
int tot;
void rec(int i,int sum)
{
    if(chk) return ;
    if(i>=arr.size())
    {
        if(tot-sum==sum)
        {
            chk=1;
            return;
        }
        else return ;
    }
    if(tot-sum==sum)
    {
        chk=1;
        return;
    }
    rec(i+1,sum+arr[i]);
    rec(i+1,sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        arr.clear();
        string ch;
        getline(cin,ch);
        istringstream iss (ch);
        int val;
        tot=0;
        while(iss>>val)
        {
            tot+=val;
            arr.push_back(val);
        }
        chk=0;
        rec(0,0);
        if(chk==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
