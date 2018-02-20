#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T>void g(T&&val);
int i = 0;const const int ci = i;
g(i); // T: int&, val int&
g(ci);//T: const int &,val :const int &
//注意！！下面这句是错的，T 是int而不是int&&
g(i*ci);// T:int &&, val: int &&
g(i=ci);//T:int &,val int&

template<typename T> void g(T val);
g(i); // T: int, val int
//注意！！下面这个是错的，顶层const会被忽略的，T是int而不是const int
g(ci);//T: const int ,val :const int
g(i*ci);// T:int &&, val: int &&
g(i=ci);//T:int,val int

template<typename T> void g(const T& val);
g(i); // T: int, val: const int&
g(ci);//T: int ,val: const int&
//注意！！下面这句是错的，T 是int而不是int&&
g(i*ci);// T:int &&, val: const int &
g(i=ci);//T:int,val: const int&

// 练习16.45
template<typename T>
void g(T&& val)
{
    vector<T> v;
}
g(42);// T:int
g(int i);//T:

// So case 1, when passing 42, you are calling g with a rvalue, so T is resolved to int thus g's parameter is int&& and std::vector is legal.

// In case 2, when passing i, you are calling g with a lvalue, so T is resolved to int& thus g's parameter is int& and std::vector<int&> is NOT legal.

// Remove the line with the vector and it will work fine in both cases.

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
