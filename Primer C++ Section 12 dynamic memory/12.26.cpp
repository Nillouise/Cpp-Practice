#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    auto allo = allocator<string>();
    auto p = allo.allocate(10);
    auto q = p;
    for(q = p;q!=p+10;q++)
    {
        string s;
        cin>>s;
        allo.construct(q,s);
    }
    for(auto n = p;n!=p+10;n++)
    {
        cout<<*n;
    }
    while(q!=p)
    {
        --q;
        allo.destroy(q);
    }
    allo.deallocate(p,10);
    
    return 0;
}
