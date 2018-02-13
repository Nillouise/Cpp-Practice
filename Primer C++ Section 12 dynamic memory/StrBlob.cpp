#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

class StrBlobPtr;
class StrBlob{
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty()const{return data->empty();}
    void push_back(const string &t){data->push_back(t);}
    void pop_back();
    string& front();
    string& back();
    
    StrBlobPtr begin();
    StrBlobPtr end();
    //这是错的，不能使用未完成的类去定义变量
    // StrBlobPtr begin(){return StrBlobPtr(*this);}
    // StrBlobPtr end()
    // {
    //     auto ret = StrBlobPtr(*this,data->size());
    //     return ret
    // }
    
    //练习12.2
    const string& front()const;
    const string& back() const;
    
// private:
    shared_ptr<vector<string>> data;
    void check(size_type i,const string &msg)const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string>il):
                data(make_shared<vector<string>>(il)){}
void StrBlob::check(size_type i,const string &msg)const
{
    if(i>=data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front()const
{
    check(0,"front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back()const
{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr
{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a,size_t sz = 0):
            wptr(a.data),curr(sz){}
    string& deref()const;
    StrBlobPtr& incr();
    bool eq(const StrBlobPtr &rhs)const
    {
        auto a = wptr.lock();
        auto b = rhs.wptr.lock();
        if(a&&b)
        {
            return a==b&&curr==rhs.curr;
        }
        return false;
    }
private:
    shared_ptr<vector<string>> check(std::size_t,const string&)const;
    weak_ptr<vector<string>>wptr;
    size_t curr;
    
};

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i,const string &msg)const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i>= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref()const
{
    auto p = check(curr,"dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin(){return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this,data->size());
    return ret;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    ios::sync_with_stdio(false);
    //联系12.1
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
    }
    
    for(auto a = b1.begin();!a.eq(b1.end());a.incr()){
        cout<<a.deref();
    }
    
    // for(auto a:*b1.data){
    //     cout<<a<<endl;
    // }
    
    return 0;
}
