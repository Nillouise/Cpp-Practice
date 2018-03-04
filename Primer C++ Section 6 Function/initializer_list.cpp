#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int sum(initializer_list<int> lst)
{
    int res = 0;
    for(auto a:lst){
        res+=a;
    }
    return res;
}



int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    sum(13,4);//这样是调用不到initializer_list的
    // sum({13,4});
    
    
    
    return 0;
}
