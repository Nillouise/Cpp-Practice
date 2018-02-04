#include <iostream>
using namespace std;


class F{
public:
  void fun(int);
  void fun(){
    cout<<"F fun()"<<endl;
  };
};

class C:private F{
public:
  void fun(int a){
    cout<<" C fun(int)\n";
  }
};


int main()
{
  C c;
  // c.F::fun();
  c.fun(4);
}