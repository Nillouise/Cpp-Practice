#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T>
class Screen;

template<typename T>
ostream&operator<<(ostream&out,Screen<T>&screen);
template<typename T>
istream&operator>>(istream&in,Screen<T>&screen);

template<typename T>
class Screen
{
    //这里好像必须要加一个<T>才行
    friend ostream& operator<< <T>(ostream&out,Screen<T>&screen);
    friend istream& operator>> <T>(istream&in,Screen<T>&screen);
public:
    T width,height;
};

template<typename T>
ostream& operator<<(ostream& out,Screen<T> &screen)
{
    out<<screen.width<<" "<<screen.height;
    return out;
}

template<typename T>
istream& operator>>(istream& in,Screen<T> &screen)
{
    in>>screen.width>>screen.height;
    return in;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    Screen<int> s;
    cin>>s;
    cout<<s;
    
    
    return 0;
}
