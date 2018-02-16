#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class Eq
{
public:
    bool operator()(int a,int b)
    {
        return a==b;
    }
};


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    Eq eq;
    vector<int> vec(10,7);
    //这里可以不用bind，直接在创建Eq对象的时候把要比较的值赋进去。
    replace_if(vec.begin(),vec.end(),bind(eq,placeholders::_1,7),3);
    
    for(auto a:vec)
    {
        cout<<a<<" ";
    }
    
    return 0;
}
