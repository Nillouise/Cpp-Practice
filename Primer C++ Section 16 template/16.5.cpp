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
    
    print(s);
    cout<<endl<<array_size(s);
    
    return 0;
}
