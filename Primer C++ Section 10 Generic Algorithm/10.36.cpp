#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    list<int> lis={0,1,4,0,6};
    auto it = find(lis.rbegin(),lis.rend(),0);
    // auto cnt = lis.rend().base()-it.base();
    // cout<<cnt<<endl;
    //相减好像是看不到距离的，要用distance函数
    std::cout << std::distance(it, lis.rend()) << std::endl;
    
    return 0;
}
