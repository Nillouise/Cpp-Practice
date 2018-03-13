#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Screen{
public:
    typedef string::size_type pos;
    char get_cursor() const{
        return contents[cursor];
    }
    char get() const;
    char get(pos ht,pos wd)const;
    static const string Screen::*data(){
        return &Screen::contents;
    }
    static const pos Screen::*pCursor(){
        return &Screen::cursor;
    }
    
private:
    string contents;
    pos cursor;
    pos height,width;
};



int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    // const string Screen::*pdata;
    Screen s;
    auto p = Screen::pCursor();
    cout<<typeid(p).name()<<endl;
    auto d = s.*p;
    cout<<d<<endl;
    cout<<(s.*p)<<endl;
    
    
    
    return 0;
}