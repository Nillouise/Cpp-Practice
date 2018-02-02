#include <algorithm>
#include <iostream>

using namespace std;

class Quote{
};

class Disc_quote: public Quote {
public:
  //纯虚函数不能定义函数体
  virtual void prin()=0;
};

class Bulk_quote: public Disc_quote{
public:
  virtual void prin(){
    cout<<"Bulk_quote"<<endl;
  }
};



int main()
{
  Bulk_quote q;
  Disc_quote& b = q;
  b.prin();
}