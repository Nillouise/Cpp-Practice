#include <algorithm>
#include <iostream>
#include<string>
using namespace std;

class Scales_data
{
public:
  operator string()const
  {
    return "inplicited convert to string";
  }
};

int main()
{
  Scales_data d;
  string s = d;
  cout<<s;
  
  return 0;
}