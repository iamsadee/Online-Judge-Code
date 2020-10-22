#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pp{
    double first,second;

};
pair<double,double> chk(pp A, pp B, pp C, pp D)
{
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);
    double x = (b2*c1 - b1*c2);
    double y = (a1*c2 - a2*c1);
    double determinant = a1*b2 - a2*b1;
    if (determinant == 0)
    {
        if(x==0 && y==0)
        {
            return make_pair(9500,9500);
        }
        else return make_pair(10000,10000);
    }
    else
    {
        double x1 = (b2*c1 - b1*c2) /(determinant*1.0);
        double y1 = (a1*c2 - a2*c1) /(determinant*1.0);
        return make_pair(x1, y1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int n;
    int n;
    cin>>n;
    pp arr[n+1][5];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i][1].first>>arr[i][1].second;
        cin>>arr[i][2].first>>arr[i][2].second;
        cin>>arr[i][3].first>>arr[i][3].second;
        cin>>arr[i][4].first>>arr[i][4].second;
    }
    cout<<"INTERSECTING LINES OUTPUT"<<"\n";
    for(int i=1;i<=n;i++)
    {
        pair<double,double> res=chk(arr[i][1],arr[i][2],arr[i][3],arr[i][4]);
        if(res.first==9500)
        {
            cout<<"LINE"<<"\n";
        }
        else if(res.first==10000)
        {
            cout<<"NONE"<<"\n";
        }
        else
        {
            cout << std::fixed;
            cout<<"POINT "<<std::setprecision(2)<<res.first<<" "<<std::setprecision(2)<<res.second<<"\n";

        }
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
