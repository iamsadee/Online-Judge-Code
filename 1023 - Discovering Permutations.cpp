#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        int j=0;
        int n,k;
        cin>>n>>k;
        string s;
        int cnt=0;
        for(char a='A'; a<='Z'; a++)
        {
            j++;
            s.push_back(a);
            if(j==n)
                break;
        }
        cout<<"Case "<<i<<":\n";
        do
        {
            if(cnt>=k)
                break;
            else
            {
                cnt++;
                cout<<s<<"\n";

            }
        }
        while ( std::next_permutation(s.begin(),s.end()) );
    }

    return 0;
}
