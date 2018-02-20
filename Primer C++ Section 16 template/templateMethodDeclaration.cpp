//看看怎么类外定义普通类的模板成员的
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class DebugDelete;


class DebugDelete
{
public:
    DebugDelete(ostream&s = cerr):os(s){}
    template<typename T> void operator()(T *p)const;
    // {
    //     os<<"deleteing unique_ptr"<<endl;
    //     delete p;
    // }
private:
    ostream &os;
};

template<typename T>
void DebugDelete::operator()(T *p)const
{
    os<<"deleteing unique_ptr"<<endl;
    delete p;    
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    DebugDelete()(new int);
    
    
    return 0;
}
