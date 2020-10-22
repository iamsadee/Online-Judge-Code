#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ap
{
    char a;
    int num;
};
bool compare(ap x,ap y)
{
    if(x.num==y.num)
    {
        return x.a<y.a;
    }
    return x.num>y.num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    ap arr[27];
    cin.ignore();
    string ch;
    int j;
    map<char,int> mp;
    map<char,int>::iterator it;
    for(int i=1; i<=n; i++)
    {
        getline(cin,ch);
        int m=ch.size();
        for(j=0; j<m; j++)
        {
            ch[j]=toupper(ch[j]);
            if(ch[j]>='A' && ch[j]<='Z')
            {
                mp[ch[j]] +=1;
            }
        }
    }
    j=0;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        arr[j].a=(*it).first;
        arr[j].num=(*it).second;
        j++;
    }
    sort(arr,arr+j,compare);
    for(int i=0; i<j; i++)
    {
        cout<<arr[i].a<<' '<<arr[i].num<<'\n';
    }


    return 0;
}
