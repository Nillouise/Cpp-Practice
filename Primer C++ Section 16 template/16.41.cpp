#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


// Exercise 16.41:
// Write a version of sum with a return type that is guaranteed to be large
// enough to hold the result of the addition.
//可以看到这个操作空间很大，可以decltype可以从实参中推导出要多大的数。
template<typename T>
auto sum(T lhs, T rhs) -> decltype( lhs + rhs)
{
    return lhs + rhs;
}



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // int a = 1000000000000000000000000000000000000000000000000000000000000;
    
    auto s= sum<__int128>(123456789123456789123456789123456789123456789, 123456789123456789123456789123456789123456789);
    // cout<<s<<endl;
    while(s)
    {
        int a = s%10;
        cout<<a;
        s/=10;
    }
    
    return 0;
}
