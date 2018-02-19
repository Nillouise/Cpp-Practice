#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T>
int compare(const T &v1,const T &v2)
{
    if(v1<v2)return -1;
    if(v2<v1)return 1;
    return 0;
}

class Foo
{
public:
    bool operator<(const Foo&f)const{
        return less<const Foo*>()(this,&f); // 嗯，这段代码需要加const才能保持类型一致
    }
};

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cout<<compare(1,0)<<endl;
    cout<<compare(Foo(),Foo());//Foo 没有定义小于运算符
    
    
    return 0;
}
