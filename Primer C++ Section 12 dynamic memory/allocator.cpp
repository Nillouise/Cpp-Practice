#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    allocator<int> allo;
    auto p = allo.allocate(10);
    for(auto q = p;q!=p+10;q++)
    {
        allo.construct(q,12);
    }
    
    for(auto q = p;q!=p+10;q++)
    {
        cout<< *q<<" ";
    }
    
    
    return 0;
}
