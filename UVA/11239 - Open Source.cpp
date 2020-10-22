#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct project
{
    ll num;
    string namepj;

};
bool compare(project x,project y)
{
    if(x.num==y.num)
    {
        return x.namepj<y.namepj;
    }
    return x.num>y.num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ch,a;
    map<string,string> mp;
    map<string,string>::iterator it;
    map<string,ll> name;
    map<string,ll>::iterator yo;
    map<string,bool> baad;
    map<string,bool> ::iterator itt;
    while(getline(cin,ch))
    {
        if(ch=="0")
        {
            project pj[105];
            //cout<<"Sadee1"<<endl;
            for(itt=baad.begin(); itt!=baad.end(); itt++)
            {
                string b=(*itt).first;
                mp.erase(b);
            }
            //cout<<"Sadee2"<<endl;
            for(it=mp.begin(); it!=mp.end(); it++)
            {
                name[(*it).second] +=1;
            }
            //cout<<"Sadee3"<<endl;
            int i=0;
            for(yo=name.begin(); yo!=name.end(); yo++)
            {
                //cout<<(*yo).first<<' '<<(*yo).second<<endl;
                pj[i].namepj =  (*yo).first;
                pj[i].num = (*yo).second ;
                i++;
            }
            sort(pj,pj+i,compare);
            for(int j=0; j<i; j++)
            {
                cout<<pj[j].namepj<<' '<<pj[j].num<<'\n';
            }
            mp.clear();
            baad.clear();
            name.clear();
            break;
        }
        if(ch[0]>='A' && ch[0]<='Z')
        {
            a=ch;
            name[a]=0;
        }
        if(ch=="1")
        {
            project pj[105];
            //cout<<"Sadee1"<<endl;
            for(itt=baad.begin(); itt!=baad.end(); itt++)
            {
                string b=(*itt).first;
                mp.erase(b);
            }
            //cout<<"Sadee2"<<endl;
            for(it=mp.begin(); it!=mp.end(); it++)
            {
                name[(*it).second] +=1;
            }
            //cout<<"Sadee3"<<endl;
            int i=0;
            for(yo=name.begin(); yo!=name.end(); yo++)
            {
                //cout<<(*yo).first<<' '<<(*yo).second<<endl;
                pj[i].namepj =  (*yo).first;
                pj[i].num = (*yo).second ;
                i++;
            }
            sort(pj,pj+i,compare);
            for(int j=0; j<i; j++)
            {
                cout<<pj[j].namepj<<' '<<pj[j].num<<'\n';
            }
            mp.clear();
            baad.clear();
            name.clear();
        }
        else if(ch[0]>='a' && ch[0]<='z')
        {
            if(mp[ch].size()==0)
            {
                mp[ch]=a;
            }
            else if(mp[ch].size()>0)
            {
                if(mp[ch]!=a)
                {
                    baad[ch]=1;
                }
            }
            //cout<<"Sadee"<<endl;
        }
    }
    return 0;
}
