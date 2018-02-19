#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Foo
{
public:
    Foo(int x):x(x){}
    int x;
};

class Bar:public Foo
{
    using Foo::Foo;//子类并不会自动继承父类的构造函数，使用using才能去重用他们
};

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // Foo f(0);
    // Bar b;//这是错的，因为父类没有默认构造函数，子类的默认构造函数就不能调用父类的默认构造函数
         // 于是就会被定义成删除的
    Bar b(0);//这也是错的，子类并不会继承父类的构造函数；
    return 0;
}
