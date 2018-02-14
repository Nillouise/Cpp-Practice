#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class HasPtr
{
public:
    HasPtr(const string&s = string()):
        ps(new string(s)),i(0){}
    HasPtr(const HasPtr& rhs):
        ps(new string(*rhs.ps)),
        i(i)    
        {}
private:
    string *ps;
    int i;
}



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
