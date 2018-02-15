#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    // HasPtr& operator=(const HasPtr &hp) {
    //     auto new_p = new std::string(*hp.ps);
    //     delete ps;
    //     ps = new_p;
    //     i = hp.i;
    //     return *this;
    // }
    HasPtr& operator=(HasPtr tmp) 
    {
        //据实验sort不会调用自定义版本swap函数，sort应该调用的是std::swap,
        //而std::swap 又会调用本赋值赋值函数
        // this->swap(tmp);
        *this = tmp;
        return *this;
    }

    ~HasPtr() {
        delete ps;
    } 
    
    void show() { std::cout << *ps << std::endl; }
    bool operator<(const HasPtr& rhs)
    {
        // cout<<(long long)ps<<" "<<(long long)rhs.ps<<endl;//
        // return (long long)ps<(long long)rhs.ps;
        cout<<i<<" "<<rhs.i<<endl;
        return i<rhs.i;
    }
// private:
    std::string *ps;
    int i;
};

// inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}



int main()
{    
    ios::sync_with_stdio(false);
    vector<HasPtr> vec;
    for(int i=0;i<10;i++)
    {
        vec.push_back(HasPtr());
    }
    for(int i=2;i<5;i++)
    {
        vec[i] = HasPtr();
        vec[i].i = 5;
    }
    // using std::swap;
    std::sort(vec.begin(),vec.end());
    
    return 0;
}
