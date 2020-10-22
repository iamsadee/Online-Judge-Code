#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
int n,k;
int sieve[205];
vector<int> prime;
void primeSieve ( int n )
{
    sieve[0] = sieve[1] = 1;
    prime.push_back(2);
    for ( int i = 4; i <= n; i += 2 )
        sieve[i] = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 )
    {
        if ( sieve[i] == 0 )
        {
            for ( int j = i * i; j <= n; j += 2 * i )
                sieve[j] = 1;
        }
    }
    for ( int i = 3; i <= n; i += 2 )
        if ( sieve[i] == 0 )
            prime.push_back(i);
}
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;

        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }

    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;
    if (i == -1)
        return "0";
    string s = "";
    while (i >= 0)
        s +=(result[i--]+'0');
    return s;
}
string con(ll x)
{
    string s1;
    while(x>0)
    {
        s1.push_back((x%10)+'0');
        x=x/10;
    }
    reverse(s1.begin(),s1.end());
    return s1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    primeSieve(200);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0; i<k; i++)
        {
            int x;
            cin>>x;
            n-=x;
        }
        string ans="0";
        if(n>=(k))
        {
            map<int,int> mp;
            for(int i=k+1; i<=n; i++)
            {
                int j=0;
                ll x=i;
                while(x>0)
                {
                    //cout<<x<<" "<<prime[j]<<endl;
                    //getchar();
                    while((x%prime[j])==0)
                    {

                        x=x/prime[j];
                        mp[prime[j]]++;
                    }
                    if(x==1)
                    {
                        break;
                    }
                    //cout<<x<<endl;
                    j++;
                }
            }
            //cout<<"ho"<<endl;

            for(int i=1; i<=(n-k); i++)
            {
                int j=0;
                ll x=i;
                while(x>0)
                {
                    while((x%prime[j])==0)
                    {
                        x=x/prime[j];
                        mp[prime[j]]--;
                    }
                    if(x==1)
                        break;
                    j++;
                }
            }
            string nw="1";
            for(int i=1;i<=n;i++)
            {
                if(mp[i]>0)
                {
                    string a1="1";
                    string a2=con(i);
                    for(int j=1;j<=mp[i];j++)
                    {
                        a1=multiply(a1,a2);
                    }
                    nw=multiply(nw,a1);
                }
            }
            ans =findSum(ans,nw);

        }
        k--;
        if(n>=(k) && k>=0)
        {
            map<int,int> mp;
            for(int i=k+1; i<=n; i++)
            {
                int j=0;
                ll x=i;
                while(x>0)
                {
                    //cout<<x<<" "<<prime[j]<<endl;
                    //getchar();
                    while((x%prime[j])==0)
                    {

                        x=x/prime[j];
                        mp[prime[j]]++;
                    }
                    if(x==1)
                    {
                        break;
                    }
                    //cout<<x<<endl;
                    j++;
                }
            }
            //cout<<"ho"<<endl;

            for(int i=1; i<=(n-k); i++)
            {
                int j=0;
                ll x=i;
                while(x>0)
                {
                    while((x%prime[j])==0)
                    {
                        x=x/prime[j];
                        mp[prime[j]]--;
                    }
                    if(x==1)
                        break;
                    j++;
                }
            }
            string nw="1";
            for(int i=1;i<=n;i++)
            {
                if(mp[i]>0)
                {
                    string a1="1";
                    string a2=con(i);
                    for(int j=1;j<=mp[i];j++)
                    {
                        a1=multiply(a1,a2);
                    }
                    nw=multiply(nw,a1);
                }
            }
            ans =findSum(ans,nw);

        }
        cout<<ans<<endl;

    }
    return 0;
}

