#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T,unsigned N>
void print(const T (&a)[N])
{
    for(int i=0;i<N;i++)
    {
        cout<<a[i]<<" ";
    }
}


// template<typename T,unsigned N>
// iterator<T> begin(const T (&a)[N])
// {
// 
// }
// 
// template<typename T,unsigned N>
// iterator<T> end(const T(&a)[N])
// {
// 
// }

template<typename T,unsigned size>
//这里不能是const，因为返回的指针不是const指针
// T* my_begin(const T (&arr)[size])
T* my_begin(T (&arr)[size])
{
    //这里好像不能加&，因为arr本身就是一个指针，再加&会变成指针的指针（我猜
    // return &arr;
    return arr;
}

template<typename T,unsigned size>
//这里不能是const，因为返回的指针不是const指针
// T* my_end(const T(&arr)[size])
T* my_end(T(&arr)[size])
{
    // return (&arr)+size;
    return arr+size;
}

template<typename T,unsigned N>
constexpr unsigned array_size(const T (&a)[N])
{
    return N;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    string s[100];
    for(int i=0;i<100;i++)
    {
        s[i]=to_string(i);
    }
    
    // print(s);
    // cout<<endl<<array_size(s);
    
    for(auto i = my_begin(s);i!=my_end(s);i++)
    {
        cout<<*i<<" ";
    }
    
    return 0;
}
