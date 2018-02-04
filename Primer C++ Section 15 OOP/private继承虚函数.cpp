#include <iostream>
using namespace std;


class F{
public:
  virtual void fun(int a){
      cout<<"virtual F fun(int )"<<endl;
  };
  void fun(){
    cout<<"F fun()"<<endl;
  };
};

class C:protected F{
public:
  void fun(int a){
    cout<<"C fun(int)\n";
  }
};


int main()
{
  C c;
  //F is n inaccesiable Base of C
  //应该是protected 和private 继承后，压根就不能类型转换了吧。
  F& f = c;
  // c.F::fun();
  f.fun(4);
}