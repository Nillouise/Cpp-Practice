#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class StrVec
{
public:
    StrVec& operator=(initializer_list<string> lst);
    string& operator[](size_t n)
    {
        return elements[n];
    }
    const string& operator[](size_t n)const
    {
        return elements[n];
    }
private:
    string *elements;
};

StrVec& StrVec::operator=(initializer_list<string lst)
{
    auto a = allocator<string>().allocate(n);
}




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
