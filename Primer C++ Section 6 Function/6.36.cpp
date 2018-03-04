#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//括号扩错了
// string (*foo1)()[10]
string (*foo1())[10]
{
    string s[10];
    return &s;//这里要加&，类型才用string* 变成string(*)[10];
}

auto foo2()->string(*)[10]
{
    string s[10];
    return &s;//这里要加&，类型才用string* 变成string(*)[10];    
}
string sobj[10];

decltype(sobj)* foo3()
{
    string s[10];
    return &s;//这里要加&，类型才用string* 变成string(*)[10];    
}

using stype1 = string[10];
typedef string stype2[10]; 

stype1* foo4()
{
    string s[10];
    return &s;//这里要加&，类型才用string* 变成string(*)[10];        
}

stype2*foo5()
{
    string s[10];
    return &s;//这里要加&，类型才用string* 变成string(*)[10];    
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    foo3();
    
    
    
    return 0;
}
