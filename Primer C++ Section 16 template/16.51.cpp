#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T,typename... Args>
void foo(const T &t,const Args&... rest);

template<typename T,typename... Args>
void foo(const T&t,const Args&... rest)
{
    cout<<sizeof...(Args)<<endl;
    cout<<sizeof...(rest)<<endl;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int i=0;double d = 3.14;string s = "how now brown cow";
    foo(i,s,42,d);
    foo(s,42,"hi");
    foo(d,s);
    foo("hi");
    
    
    return 0;
}
