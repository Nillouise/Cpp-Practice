#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename> class BlobPtr;
template<typename> class Blob;
template<typename T>
    bool operator==(const Blob<T>&,const Blob<T>&);

template<typename T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&,const Blob<T>&);
public:
    typedef T value_type;
    //注意这里要用typename才能引出vector<T>::size_type类型,不然编译器不知道size_type是类型还是一个静态变量
    typedef typename vector<T>::size_type size_type;
    Blob();
    Blob(initializer_list<T> il);
    size_type size()const{
        return data->size();
    }
    bool empty()const
    {
        return data->empty();
    }
    void push_back(const T&t){
        data->push_back(t);
    }
    void push_back(T&& t){
        data->push_back(std::move(t));
    }
    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    shared_ptr<vector<T>>data;
    void check(size_type i,const string &msg)const;
};

template<typename T>
void Blob<T>::check(size_type i,const string &msg)const
{
    if(i>data->size())
        throw out_of_range(msg);
}

template <typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob");
    return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i,"subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0,"pop_back on empty Blob");
    data->pop_back();
}

template<typename T>
Blob<T>::Blob():
    data(make_shared<vector<T>>()){}

template<typename T>
Blob<T>::Blob(initializer_list<T> il):
    data(make_shared<vector<T>>(il)){}

template<typename T> 
class BlobPtr
{
public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T> &a,size_t sz = 0):
        wptr(a.data),curr(sz){}
    T& operator*()const
    {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
private:
    shared_ptr<vector<T>>
        check(size_t,const string&)const;
    std::weak_ptr<vector<T>>wptr;
    size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}





int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};
    for(size_t i=0;i!=squares.size();i++)
        squares[i] = i*i;
    
    // for(size_t i=0;i!=squares.size();++i)
    //     cout<<squares[i]<<" ";
    
    
    
    
    
    return 0;
}
