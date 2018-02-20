#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//模仿shared_ptr
template<typename T>
class SP
{
    T* p;
    int *cnt;
    function<void (T*)> d;
public:
    SP(T*p):p(p),cnt(new int(1)){}
    SP(T*p,function<void(T*)> d):p(p),d(d),cnt(new int(1)){
    // SP(T*p,function<void(T*)> d):p(p),d(d){
        cout<<"construct point "<<*p<<endl;
        cout<<cnt<<" random value: "<<*cnt<<endl;//
    }
    
    void reset(T*p,function<void(T*)> d)
    {
        free();
        cnt = new int(1);
        this.p=p;
        this.d=d;
    }
    
    SP(const T&rhs)
    {
        p = rhs.p;
        cnt = rhs.cnt;
        d = rhs.d;
        *cnt++;
    }
    
    SP& operator=(const T&rhs)
    {
        if(this!=&rhs)
        {
            free();
            p=rhs.p;
            d=rhs.d;
            cnt = rhs.cnt;
            *cnt++;
        }
    }
        
    ~SP()
    {
        cout<<"destruct a point "<<*p<<endl;
        free();
    }
    
    void free()
    {
        cout<<"free a point: "<< *p<<endl;
        if(--*cnt == 0)
        {
            //这里乱delete会导致程序异常终结
            delete cnt;
            d?d(p):delete p;
        }
    }
};

//模仿unique_ptr,这里处理不了delete[] 动态数组的问题呀
//写了个全是bug的up
template<typename T,typename DEL = void(T*)>
class UP
{
    T* p;
    DEL d;
public:
    UP(T* p):
        //好像不能在这里定义lambda表达式
        // p(p),d([](T *p){delete p;}){}
        p(p),d(UP::free){}
    UP(T *p,DEL d):
        p(p),d(d){}
    T* release(){
        T* tmp = p;
        p=nullptr;
        return tmp;
    }
    UP(const UP<T,DEL>&rhs)=delete;
    operator=(const UP<T,DEL>&rhs)=delete;
    
    static void free(T *p){delete p;}
    ~UP()
    {
        if(p!=nullptr)
        {
            d(p);
        }
    }
    
    
};


void fun()
{
    
    SP<string> s(new string("first ptr"),[](string *s)-> double {delete s;return 0.0;});
    SP<string> s2(new string("second ptr"),[](string *s){delete s;});
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    fun();
    
    return 0;
}
