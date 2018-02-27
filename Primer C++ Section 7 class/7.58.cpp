#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Example{
public:
    //这里应该是错的，不能再类内给非const或constexpr的静态成员赋值
    static double rate = 6.5;
    //这个应该是对的，但不能被其他地方是用
    static const int vecSize = 20;
    //这个应该是对的，因为vecSize是常量//错了！！！
    //we may not specify an in-class initializer inside parentheses.
    //就是说静态变量不能调用构造函数
    static vector<double> vec(vecSize);
};

double Example::rate;
vertor<double> Example::vec;

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
