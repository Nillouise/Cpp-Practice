#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class SmallInt
{
public:
    SmallInt(int i=0):val(i)
    {
        if(i<0||i>255)
            throw out_of_range("Bad SmallInt value");
    }
    operator int() const{
        return val;
    }
    operator bool() const
    {
        return val>0;
    }
private:
    size_t val;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
