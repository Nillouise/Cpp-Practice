#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(),data.end());
    cout<<"right value sorted"<<endl;
    return *this;
}

//正确版本
// Foo Foo::sorted() const &
// {
//     Foo ret(*this);
//     sort(ret.data.begin(),ret.data.end());
//     return ret;
// }

//这会导致递归调用自身
// Foo Foo::sorted() const &
// {
//     Foo ret(*this);
//     cout<<"left value sorted"<<endl;
//     return ret.sorted();
// }


Foo Foo::sorted() const &
{
    cout<<"left value sorted"<<endl;
    //这会调用右值排序
    return Foo(*this).sorted();
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    Foo f;
    f.sorted();
    
    
    return 0;
}
