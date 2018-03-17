#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Base {
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
};

class Base1 {
public:
    virtual void f() { cout << "Base1::f" << endl; }
    virtual void g() { cout << "Base1::g" << endl; }
    virtual void h() { cout << "Base1::h" << endl; }
};

class Base2 {
public:
    virtual void f() { cout << "Base2::f" << endl; }
    virtual void g() { cout << "Base2::g" << endl; }
    virtual void h() { cout << "Base2::h" << endl; }
};

class Base3 {
public:
    virtual void f() { cout << "Base3::f" << endl; }
    virtual void g() { cout << "Base3::g" << endl; }
    virtual void h() { cout << "Base3::h" << endl; }
};

class Deri:public Base1,public Base2,public Base3 {
public:
    virtual void f(){cout<<"Deri::f"<<endl;}
};


int main()
{
    // freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // typedef void(*Fun)(void);
    // Base b;
    // Fun pFun = NULL;
    // cout << "虚函数表地址：" << (int*)(&b) << endl;
    // cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
    // // Invoke the first virtual function 
    // pFun = (Fun)*((int*)*(int*)(&b));
    // pFun();
    
    // Deri d;
    // d.f();
    Deri *pd = new Deri;
    Base1 *pb1 = pd;
    Base2 *pb2 = pd;
    Deri *prd = (Deri*)pb2;
    
    cout<<"deri pointer:"<<(int *)pd<<endl;
    cout<<"base1 pointer:"<<(int *)pb1<<endl;
    //可以看出，pb2在编译器就会被偏移掉
    cout<<"base2 pointer:"<<(int *)pb2<<endl;
    cout<<"revert Deri pointer:"<<(int *)prd<<endl;
    pb2->g();
    
    
    return 0;
}