#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Screen{
public:
    typedef string::size_type pos;
    char get_cursor() const{
        return contents[cursor];
    }
    char get() const{};
    char get(pos ht,pos wd)const{};
    Screen& home(){};
    Screen& forward(){};
    Screen& back(){};
    Screen& up(){};
    Screen& down(){};
    using Action = Screen&(Screen::*)();//感觉这个可能是重点
    enum Directions{HOME,FORWARD,BACK,UP,DOWN};
    Screen& move(Directions);
    
    static const string Screen::*data(){
        return &Screen::contents;
    }
    static const pos Screen::*pCursor(){
        return &Screen::cursor;
    }
    
private:
    static Action Menu[];
    string contents;
    pos cursor;
    pos height,width;
};

Screen& Screen::move(Directions cm)
{
    return (this->*Menu[cm])();
}
Screen::Action Screen::Menu[] = {
    &Screen::home,
    &Screen::forward,
    &Screen::back,
    &Screen::up,
    &Screen::down,
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
    
    // auto pmf = &Screen::get_cursor;
    auto pmf = &Screen::get;
    
    return 0;
}