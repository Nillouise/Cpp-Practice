#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class HasPtr
{
public:
    HasPtr(const string &s=string()):
    HasPtr(const HasPtr&p):
        ps(p.ps),i(p.i),use(p.use){++*use;}
    HasPtr& operator=(const HasPtr&);
    ~HasPtr()
    {
        if(--*use == 0)
        {
            delete ps;
            delete use;
        }
    }
private:
    string *ps;
    int i;
    int *use;
};

HasPtr& HasPtr::operator=（const HasPtr &rhs)
{
    ++*rhs.use;
    if(--*use==0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i=rhs.i;
    use = rhs.use;
    return *this;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
