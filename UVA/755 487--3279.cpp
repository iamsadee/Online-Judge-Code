#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j,k;
    scanf("%d\n",&t);
    map<char,char> mp;
    mp['A']='2';
    mp['B']='2';
    mp['C']='2';
    mp['D']='3';
    mp['E']='3';
    mp['F']='3';
    mp['G']='4';
    mp['H']='4';
    mp['I']='4';
    mp['J']='5';
    mp['K']='5';
    mp['L']='5';
    mp['M']='6';
    mp['N']='6';
    mp['O']='6';
    mp['P']='7';
    mp['R']='7';
    mp['S']='7';
    mp['T']='8';
    mp['U']='8';
    mp['V']='8';
    mp['W']='9';
    mp['X']='9';
    mp['Y']='9';
    for(i=1;i<=t;i++)
    {
        int x,y;
        map<string,int> st;
        scanf("%d\n",&n);
        //getchar();
        //getchar();
        for(j=1;j<=n;j++)
        {
            x=0;
            int chk=0;
            string a,b;
            getline(cin,a);
            for(k=0;k<a.size();k++)
            {
                if(x==3 && chk==0)
                {
                    chk=1;
                    b.push_back('-');
                }
                if(a[k]>='A' && a[k]<'Z')
                {
                    x++;
                    b.push_back(mp[a[k]]);
                }
                if(a[k]>='0'&& a[k]<='9')
                {
                    x++;
                    b.push_back(a[k]);
                }
            }
            //cout<<b<<endl;
            st[b]+=1;
        }

        int cnt=0;
        map<string,int>::iterator it;
        for(it=st.begin();it!=st.end();it++)
        {
            if((*it).second >1 ){
            cout<<(*it).first<<' '<<(*it).second<<endl;
            cnt++;
            }
        }
        //cout<<cnt<<endl;
        if(cnt==0)
        {
            cout<<"No duplicates."<<endl;
        }
        if(i!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
