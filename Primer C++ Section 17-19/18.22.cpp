#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class A{};
class B: public A{};
class C: public B{};
class X{};
class Y{};
class Z:public X,public Y{};
class MI: public C,public Z{};

MI mi;
// 顺序 A B C X Y Z


int main()
{
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}