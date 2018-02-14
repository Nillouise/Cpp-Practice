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
        i(rhs.i)    
        {}
    //仔细看下面的各种引用解引用，我写错好多
    HasPtr& operator= (const HasPtr &p)
    {
        if(&p!=this)//防止自赋值
        {
            string *tmp = new string(*p.ps);
            delete ps;//先申请内存，后delete，应该是为了防止申请内存时产生的异常
            ps = tmp;
            i = p.i;
        }
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }
    
private:
    string *ps;
    int i;
};



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
