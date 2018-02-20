#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


template <typename T> void f(T)
{
    std::cout << "template f(T)\n";
}

template <typename T> void f(const T*)
{
    std::cout << "template f(const T*)\n";
}
template <typename T> void g(T)
{
    std::cout << "template <typename T> void g(T)\n";
}
template <typename T> void g(T*)
{
    std::cout << "template <typename T> void g(T*)\n";
}



int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    cout<<"g(42)"<<endl;
    g(42);    //template <typename T> void g(T ); --is called
    cout<<"g(p)"<<endl;
    g(p);     //template <typename T> void g(T*); --is called
    cout<<"g(ci)"<<endl;
    g(ci);      //template <typename T> void g(T)   --is called
    cout<<"g(p2)"<<endl;
    g(p2);      //template <typename T> void g(T*)    --is called
    cout<<"f(42)"<<endl;
    f(42);    //f(T)
    cout<<"f(p)"<<endl;
    f(p);     //f(T)
    cout<<"f(ci)"<<endl;
    f(ci);    //f(T)
    cout<<"f(p2)"<<endl;
    f(p2);      //f(const T*)



}
