#include <iostream>

using namespace std;
//这个例子中，我想明白了，假如调用的函数是父类的，那就不会使用子类的同名变量

class F{
public:
  int a;
  virtual void prin(){
    cout<<"F "<<a<<endl;
  }
  F():a(42){}
};

class C : public F{
public:
  C():a(63){}
  int a;
  virtual void prin(){
    cout<<"C "<<a<<endl;
    F::prin();
  }
};



int main()
{
  C a;
  F *b = &a;
  F c = a;
  c.prin();
  b->prin();
  
}