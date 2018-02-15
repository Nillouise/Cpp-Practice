#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


class String
{
    static allocator<char> alloc;
public:
    String()=default;
    String(const char*p);
    ~String()
    {
        alloc.deallocate(p,cap);
    }
    String(const String &rhs);
    StrVec(StrVec &&s)noexcept;
private:
    char *p=nullptr;
    int cap = 0;
    void copy_from_char(const char *p);
};
allocator<char> String::alloc = allocator<char>();

StrVec::StrVec(StrVec &&s)noexcept
:elements(s.elements),first_free(s.first_free)noexcept
{
    s.elements = s.first_free = s.cap = nullptr;
}

String::String(const String &rhs)
{
    copy_from_char(rhs.p);
    cap = rhs.cap;
}

void String::copy_from_char(const char *p)
{
    int sz = strlen(p);
    char* np = alloc.allocate(sz+1);
    for(auto i=np;i!=np+sz+1;i++)
    {
        *i = *(p+(i-np)); 
    }
    *(np+sz) = '\0';
    // for(auto i = np;i!=np+sz+1;i++)
    // {
    //     alloc.construct(*i,*(p+(i-np)));
    // }
    // alloc.construct(*(np+sz),'\0');    
    cap = sz+1;
}

String::String(const char *p)
{
    copy_from_char(p);
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
