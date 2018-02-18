#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Base
{
public:
    virtual int fcn(){cout<<"Base fcn()"<<endl;return 0;};
};

class D1 :public Base
{
public:
    int fcn(int){cout<<"D1 fcn(int)"<<endl;return 0;};
    virtual int fcn(){
        cout<<"D1 fcn()"<<endl;return 0;
    };
    virtual void f2(){cout<<"D1 f2()"<<endl;};
};


// class D2 :public D1
// {
// public:
//     int fcn(int);
//     int fcn();
//     void f2();
// };


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    D1 d;
    d.fcn();
    
    
    
    return 0;
}
