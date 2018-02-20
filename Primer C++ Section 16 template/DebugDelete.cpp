#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class DebugDelete
{
public:
    DebugDelete(ostream&s = cerr):os(s){}
    template<typename T> void operator()(T *p)const
    {
        os<<"deleteing unique_ptr"<<endl;
        delete p;
    }
private:
    ostream &os;
};



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    double *p = new double;
    // DebugDelete d;
    // d(p);
    unique_ptr<int,DebugDelete> n(new int,DebugDelete());
    
    
    
    return 0;
}
