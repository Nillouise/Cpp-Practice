#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    const int *wi = new const int;//这是错的，const int 必须要绑定值
    const string *rs = new const string;//这是对的，因为string能默认绑一个值 
    const int *pi = new const int();
    cout<<*pi<<endl;//
    
    return 0;
}
