#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Foo
{
public:
    virtual void call(){
        cout<<"Foo call"<<endl;
    }
    virtual void noDestructor(){
        //这里会调用子类的虚函数
        call();
    }
    virtual ~Foo(){
        //这里并不会调用子类的虚函数
        this->call();
    }
};
class Bar:public Foo
{
public:
    virtual void call(){
        cout<<"Bar call"<<endl;
    }
};

void test()
{
    Foo *f = new Bar();
    f->noDestructor();
    delete f;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    test();
    
    
    return 0;
}
