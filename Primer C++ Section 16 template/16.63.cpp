#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T,typename U>
int cnt(const vector<T> &vec,U v)
{
    int res=0;
    for(auto a:vec)
    {
        res+=a==v;
    }
    return res;
} 

template<>
int cnt(const vector<const char*>&v,const char* s)
{
    int res=0;
    for(auto a:v)
    {
        res+=string(a)==string(s);
    }
    return res;
}

int main()
{
    // for ex16.63
    std::vector<double> vd = { 1.1, 1.1, 2.3, 4 };
    std::cout << cnt(vd, 1.1) << std::endl;
    
    // for ex16.64
    std::vector<const char*> vcc = { "alan", "alan", "alan", "alan", "moophy" };
    std::cout << cnt(vcc, "alan") << std::endl;

    return 0;
}
