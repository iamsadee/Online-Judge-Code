#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int k;
        scanf("%d",&k);
        int n=1;
        vector<int> ans;
        map<int,int> mp;
        while(1)
        {
            int x=(n*(n+1))/2;
            //cout<<x<<endl;
            if(x>k)
                break;
            ans.push_back(x);
            mp[x]=1;
            n++;
        }
        bool chk=false;
        for(int j=0;j<ans.size();j++)
        {
            //cout<<ans[j]<<endl;
            if(chk)
                break;
            for(int l=0;l<ans.size();l++)
            {
                if(mp[k-ans[j]-ans[l]]==1)
                {
                    chk=1;
                    //cout<<"chk4"<<endl;
                    break;
                }
            }
        }
        printf("%d\n",chk);
    }
    return 0;
}

