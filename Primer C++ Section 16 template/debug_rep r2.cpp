#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T> 
string debug_rep(const T&t)
{
    stringstream ret;
    ret<<t;
    return ret.str();
}

template<typename T>string debug_rep(T*p)
{
    ostringstream ret;
    ret<<"pointer: "<<p;
    // cout<<"pointer: "<<p;
    if(p)
        ret<<" "<<debug_rep(*p);
    else
        ret<<" null pointer";
    cout<<"template<typename T>string debug_rep(T*p)"<<endl;
    return ret.str();
}

// string debug_rep(const char*p)
// {
//     cout<<"debug_rep (const char*p)"<<endl;
//     return debug_rep(string(p));
// }
string debug_rep(char*p)
{
    cout<<"debug_rep (char*p)"<<endl;
    return debug_rep(string(p));
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // const string s("hi");
    // cout<<debug_rep(&s)<<endl;
    
    const char *a = "ok";
    cout<<debug_rep(a);
    
    
    return 0;
}
