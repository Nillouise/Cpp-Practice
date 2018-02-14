#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x)
{
    std::vector<X> vec;
    cout<<"begin reverse"<<endl;
    vec.reserve(2);//这里只是确保有足够的内存，不会引起构造函数。
    cout<<"end reverse"<<endl;
    vec.resize(10);//这里会引起构造函数
    vec.push_back(rx);
    vec.push_back(x);
    cout<<"vec.size() "<<vec.size()<<endl;
}
int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // X *x = new X();//这东西即使在程序结束仍然没有被析构，也就是说析构函数可能完全不被执行
    
    X *px = new X;
    f(*px, *px);
    delete px;
    return 0;
}
