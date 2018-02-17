#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    map<string,function<double(double,double)>> funs=
    {
        {"+",[](double x,double y){return x+y;}},
        {"-",[](double x,double y){return x-y;}},
        {"*",[](double x,double y){return x*y;}},
        {"/",[](double x,double y){return x/y;}}
    };
    cout<<funs["+"](1,2);
    
    
    return 0;
}
