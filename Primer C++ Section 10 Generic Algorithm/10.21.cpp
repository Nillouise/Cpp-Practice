#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int i=10;
    //这里的mutable的意思应该是，当创建了这个lambda对象后，
    // 被拷贝捕获的对象的修改会一直存在整个lambda对象的生命周期
    auto f = [i]()mutable->bool{
        if(i>0)i--;
        return i==0;
    };
    while(!f()){
        cout<<i<<endl;//
    }
    
    return 0;
}
