#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//右值引用参数和拷贝参数会引起二义性
class Foo
{
public:
    Foo(){}
    // Foo(Foo &&f){}
    //注意这里不加const是不能接收右值的
    // Foo(Foo &f){}
    Foo(const Foo &f){}
    //这里加入引用是可以解除二义性
    // Foo& operator=(Foo &f)
    Foo& operator=(Foo f)
    {
        return *this;
    }
    Foo& operator=(Foo &&f)
    {
        return *this;
    }
};

void fun(string x){};
void fun(string &&x){};

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // Foo f1;
    // Foo f2 = f1;
    //这会导致二义性，因为优先级相同？
    // f2 = std::move(f1);
    // std::move(f1);
    // fun(0);
    fun(std::move(string()));
    
    return 0;
}
