#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Base{
    friend bool operator==(const Base&,const Base&);
public:
protected:
    virtual bool equal(const Base&)const;
};

class Derived:public Base{
public:
protected:
    bool equal(const Base &)const;
};



bool Derived::equal(const Base&rhs)const
{
    auto r = dynamic_cast<const Derived&>(rhs);
}

bool Base::equal(const Base&rhs)const
{
    
}

class A
{
public:
    virtual ~A(){
        
    }
};

class B:public A
{
public:
    virtual ~B(){
        
    }
};

class C:public B
{
public:
    virtual ~C(){
        
    }
};


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int arr[10];
    Derived d;
    Base *p = &d;
    cout<<typeid(42).name()<<endl;
    cout<<typeid(string).name()<<endl;
    cout<<typeid(p).name()<<endl;
    
    cout<<"cout<<ABC"<<endl;
    
    // A* pa = new C;
    // cout<<typeid(pa).name()<<endl;
    
    
    // C cobj;
    // A& ra = cobj;
    // cout<<typeid(&ra).name()<<endl;
    
    B *px = new B;
    A& ra = *px;
    cout<<typeid(ra).name()<<endl;
    
    return 0;
}