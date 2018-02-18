
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Base
{
public:
    Base()=delete;    
    Base(int x){this->x=x;};
    int x;
};

class Derive:public Base
{
public:
    // Derive(){
    //     cout<<"ok"<<endl;
    // };
    Derive()=default;
    Derive(int x):Base(x){};   
};




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    // Base b;//这个跟下面那个居然不一样,这是调用b的默认构造函数Base()
    // Base b(10);//这是调用b的构造函数Base(int x);
    // Base b();//这是声明一个返回base的函数
    // Base * b = new Base();//这是调用b的默认构造函数Base()
    // Base *b = new Base;//这也是调用b的默认构造函数Base()
    // int *x = new int;//执行默认初始化，也就是随机值
    int *x = new int();//执行值初始化，就是为0；
    cout<<*x<<endl;
    // cout<<b;
    // Derive d();
    
    
    return 0;
}
