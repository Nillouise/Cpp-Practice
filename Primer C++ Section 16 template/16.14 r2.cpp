#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//声明时也必须要列出他有两个模板形参
template<unsigned W,unsigned H>
class Screen;

template<unsigned W,unsigned H>
ostream& operator<< (ostream& out,const Screen<W,H> &screen);

template<unsigned W,unsigned H>
class Screen
{
    //注意，友元这里<< 后面接<W,H>是因为Screen 要指定这个函数为同类型
    //后面定义operator<<并不需要接<W,H>
    friend ostream& operator<< <W,H>(ostream&out,const Screen<W,H> &screen);
public:
    int w,h;
    Screen():w(W),h(H){
        val = string(w*h,'.');
    }
    string val;
    
};

template<unsigned W,unsigned H>
ostream& operator<< (ostream& out,const Screen<W,H> &screen)
{
    for(int i=0;i<screen.w;i++)
    {
        for(int j=0;j<screen.h;j++)
        {
            out<<screen.val[i*screen.w+j];
        }
        out<<endl;
    }
    return out;
}





int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    Screen<10,10> s;
    cout<<s<<endl;
    
    
    return 0;
}
