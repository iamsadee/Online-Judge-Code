#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,a);
        stack<char> st;
        int chk=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='(' || a[i]=='[')
            {
                st.push(a[i]);
            }
            else if(a[i]==')')
            {
                if(st.size()!=0)
                {
                    if(st.top()=='(') st.pop();
                    else st.push(a[i]);
                }
                else st.push(a[i]);
            }
            else if(a[i]==']')
            {
                if(st.size()!=0)
                {
                    if(st.top()=='[') st.pop();
                    else st.push(a[i]);
                }
                else st.push(a[i]);
            }
        }
        if(st.size()==0)
        {
            printf("Yes\n");
        }
        else printf("No\n");
        //st.empty();
    }
    return 0;
}
