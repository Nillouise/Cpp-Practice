#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Base1{
    void print(int)const;
protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};

struct Base2{
    void print(double)const;
protected:
    double fval;
private:
    double dval;
};

struct Derived:public Base1{
    void print(string)const;
protected:
    string sval;
    double dval;    
};

struct MI: public Derived,public Base2{
    void print(vector<double>);//此函数被基类的覆盖了
    void foo(double cval);
protected:
    int *ival;
    vector<double> dvec;
};

int ival;
double dval;
void MI::foo(double cval)
{
    int dval;
    dval = Base1::dval+Derived::dval;
    Base2::fval = dvec.back();
    sval[0] = Base1::cval;
}




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    MI mi;
    mi.print(42);
    
    
    
    return 0;
}