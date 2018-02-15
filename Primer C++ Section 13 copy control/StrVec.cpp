#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class StrVec
{
public:
    StrVec():
        elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(initializer_list<string> &lst);
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const{return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    string *begin() const{return elements;}
    string *end() const{return first_free;}
    
    void reserve(size_t n);
    void resize(size_t n);
private:
    static allocator<string> alloc;
    void chk_n_alloc()
    {
        if(size()==capacity())
            reallocate();
    }
    pair<string*,string*> alloc_n_copy(const string*,const string *);
    void free();
    void free_lambda_version();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};

StrVec::StrVec(initializer_list<string> &lst)
{
    alloc_n_copy(lst.begin(),lst.end());
}

void StrVec::reserve(size_t n)
{
    if(n<=capacity())
        return;
    auto newBegin = alloc.allocate(n);
    auto curBegin = newBegin;
    for(auto i = begin();i!=end();i++)
    {
        alloc.construct(curBegin++,std::move(*i));
    }
    for(auto i = begin();i!=end();i++)
    {
        alloc.destroy(i);
    }
    alloc.deallocate(begin(),capacity());
    
    first_free = newBegin + capacity();
    elements = newBegin;
    cap = newBegin + n;
}

void StrVec::resize(size_t n)
{
    if(n>capacity())
    {
        reserve(n);
    }else if(n<capacity())
    {
        for(int i=size()-1;i>=n;i--)
        {
            alloc.destroy(elements+i);
        }
        first_free = elements+n;
    }
}

allocator<string> StrVec::alloc = allocator<string>();
void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

pair<string*,string*>
StrVec::alloc_n_copy(const string *b,const string *e)
{
    auto data = alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
    if(elements)
    {
        for(auto p = first_free;p!=elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements,cap-elements);
    }
}

void StrVec::free_lambda_version()
{
    if(elements)
    {
        for_each(elements,first_free;[](string *s){alloc.destroy(s);});
        alloc.deallocate(elements,cap-elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size()?2*size():1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0;i!=size();i++)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
