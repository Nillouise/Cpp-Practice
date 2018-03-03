#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    unsigned u = 10,u2=42;
    cout<<u2-u<<endl;
    cout<<u-u2<<endl;
    
    int i=10,i2=42;
    cout<<i2-i<<endl;
    cout<<i-i2<<endl;
    cout<<i-u<<endl;
    cout<<u-i<<endl;
    cout<<3.14L<<endl;// 这是long double吗？//对
    // cout<<09<<endl;//编译错误
    cout<<3.15L<<endl;
    return 0;
}
