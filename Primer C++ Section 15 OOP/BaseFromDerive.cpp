#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Base
{
public:
    Base(){}
     virtual void prin(){
        cout<<"base prin"<<endl;
    }
    Base(Base &b){
        b.prin();
        this->x = b.x;
        cout<<"cout base.x :" <<b.x<<endl;//
    }
    string x ="Base string";
};


class Deri:public Base
{
public:
    virtual void prin() override
    {
        cout<<"Deri prin"<<endl;
    }
    string x = "Deri string";
};


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    Deri d;
    Base b=d;//结果却是会调用子类的虚函数
    cout<<b.x<<endl;
    
    
    
    return 0;
}
