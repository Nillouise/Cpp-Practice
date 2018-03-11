#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Class{
public:
    Class(){cout<<"Class()"<<endl;}
    Class(const Class&c){cout<<"Class(const Class&c)"<<endl;}
    Class(int i){cout<<"Class(int i)"<<endl;}
};
class Base:public Class{
public:
    Base(){cout<<"Base()"<<endl;} 
    Base(const Base&b){cout<<"Base(const Base&b)"<<endl;}
    Base(int i){cout<<"Base(int i)";}
};
class D1: virtual public Base{
public:
    D1(){cout<<"D1()"<<endl;}
    D1(const D1&d):Base(d){cout<<"D1(const D1&d)"<<endl;}
    D1(int i):Base(i){cout<<"D1(int i)"<<endl;}
};
class D2: virtual public Base{
public:
    D2(){cout<<"D2()"<<endl;}
    D2(const D2&d):Base(d){cout<<"D2(const D2&d)"<<endl;}
    D2(int i):Base(i){cout<<"D2(int i)"<<endl;}    
};
class MI: public D1,public D2{
public:
    MI(){cout<<"MI()"<<endl;}
    MI(const MI&mi):D1(mi),D2(mi){cout<<"MI(const MI&mi)"<<endl;}
    MI(int i):D1(i),D2(i){cout<<"MI(int i)"<<endl;}
};
class Final: public MI,public Class{
public:
    Final(){cout<<"Final()"<<endl;}
    Final(const Final&f):MI(f),Class(f){cout<<"Final(const Final&f)"<<endl;}//这里有两个class，引起二义性，我不知道怎么解决
    // Final(int i):MI(i),Class(i){cout<<"Final(int i)"<<endl;}
};


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    Final f;
    
    return 0;
}